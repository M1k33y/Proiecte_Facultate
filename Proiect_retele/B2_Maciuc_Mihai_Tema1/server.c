#include <stdio.h>
#include <sys/stat.h>
#include <utmp.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <sys/socket.h>

#define FIFO_NAME "MyTest_FIFO"
#define FIFO_RESP "ServerToClient_Fifo" 

int pid=0;
bool LOGGED=false;
bool login_comand(char *new_user)
{

  
  FILE *file = fopen("users.txt", "r");
  if (file == NULL)
  {
    perror("Eroare");
    return false;
  }

  char line[100];

  while (fgets(line, sizeof(line), file))
  {
    char user[50] = {};
    int i = 0, j = 0;

    while (line[i] != '\0' && line[i] != '\n')
    {
      user[i] = line[i];
      i++;
    }
    
    if (strcmp(user, new_user) == 0)
    {
      fclose(file);
      LOGGED = true;
      return LOGGED;
    }
  }
  fclose(file);
  return LOGGED;

}


void get_logged_users_comand(int write_fd)
{
  
  if (LOGGED == false)
  {
    char mesaj[]="Nu aveti acces, nu sunteti logat\n";
    write(write_fd,mesaj,strlen(mesaj));
    return;
  }
  printf("Am trecut");
  struct utmp *info;
  // datele din utmp sunt in binar si de aia folosesc setutent care le standardizeaza pt citire
  setutent(); // deschide fisierul utmp pentru citire
  info = getutent();
  char buffer[1000]="";
  while (info != NULL)
  {
    if (info->ut_type == USER_PROCESS)
    {

      char line[300];

      snprintf(line,sizeof(line),"Username: %s,Hostname: %s,Entry time:%s\n",
      info->ut_user,info->ut_host,ctime(&info->ut_tv.tv_sec));
     

      strcat(buffer,line);
      
    }

    info = getutent();

  }

  endutent();
  write(write_fd,buffer,strlen(buffer));
}


void get_proc_info_comand(int write_fd,int pid)
{
  if(LOGGED==0)
  {
    char mesaj[]="Nu aveti acces,nu sunteti logat";
    write(write_fd,mesaj,strlen(mesaj));
    return;
  }
  

 
char path[1000]="/proc/",line[200],cpy[10];
  sprintf(cpy,"%d",pid);
  strcat(path,cpy);
  strcat(path,"/status");

  FILE *path_file=fopen(path,"r");
  if(path_file==NULL)
  {
    perror("Eroare la deschiderea path_fileului");
    return;
  }
  char buffer[1000]="";
  while(fgets(line,sizeof(line),path_file))
  {
      if(strncmp(line,"Name:",5)==0)
        strcat(buffer,line);
       if(strncmp(line,"State:",6)==0)
        strcat(buffer,line);
       if(strncmp(line,"PPid:",5)==0)
        strcat(buffer,line);
       if(strncmp(line,"Uid:",4)==0)
        strcat(buffer,line);
       if(strncmp(line,"VmSize",6)==0)
        strcat(buffer,line);

  }
  fclose(path_file);
  write(write_fd,buffer,strlen(buffer));
}

void logout_comand()
{
  LOGGED=0;
  printf("Nu mai sunteti logat");
}



int main()
{

  char s[300];
  int num,fd,fd_resp;

  mknod(FIFO_NAME,__S_IFIFO| 0666, 0);
  mknod(FIFO_RESP,__S_IFIFO| 0666,0);

  printf("Astept sa scrie cineva...\n");
  fd = open(FIFO_NAME, O_RDONLY);
  fd_resp=open(FIFO_RESP,O_WRONLY);

  printf("A venit cineva:\n");

  do
  {
    if ((num = read(fd, s, 300)) == -1)
      perror("Eroare la citirea din FIFO!");
    else
    {
      s[num] = '\0';
      printf("S-au citit din FIFO %d bytes: \"%s\"\n", num, s);

      //comenzi
      int pipefd[2]; //pipe utilizat 
      if(pipe(pipefd)==-1){
        perror("Eroare la pipe");
        exit(EXIT_FAILURE);
      } 

     

      //facem proces copil pentru comenzi

      int internal_pipe[2];
      pipe(internal_pipe);

      pid_t child_pid=fork();
      if(child_pid==-1)
      {
        perror("Eroare la fork");
        exit(EXIT_FAILURE);
      }

      if(child_pid==0) //pt copil
      {
        close(pipefd[0]); //inchid citire
        close(internal_pipe[0]);
       // close(socket[1]); //inchid socket scriere parinte
        if(strncmp(s,"login",5)==0)
          {
            char new_user[50];
            sscanf(s+6,"%s",new_user);
            if(login_comand(new_user)==true)
            {
              char mesaj[]="Bine ai venit, ";
              strcat(mesaj,new_user);
              write(pipefd[1],mesaj,strlen(mesaj));
            }
            else
            {
              char mesaj[]="Login nereusit\n";
              write(pipefd[1],mesaj,strlen(mesaj));
            }
            
            write(internal_pipe[1],&LOGGED,sizeof(LOGGED));
          }
          else if(strcmp(s,"get-logged-users\n")==0){
        get_logged_users_comand(pipefd[1]); //trimit rezultatul prin pipe

          }
      else if(strncmp(s,"get-proc-info",13)==0)
      {
        int pid;
        sscanf(s+14,"%d",&pid);
        get_proc_info_comand(pipefd[1],pid);
      }
      else if(strcmp(s,"logout\n")==0)
      {        logout_comand();
      LOGGED=false;
      write(internal_pipe[1],&LOGGED,sizeof(LOGGED));
        write(pipefd[1],"Logout...\n",17);
      }
      else if(strcmp(s,"quit\n")==0){
        write(pipefd[1],"Serverul se inchide...\n",24);
          close(pipefd[1]);
        exit(0);

      }
      else
        write(pipefd[1],"Comanda necunoscuta!\n",strlen("Comanda necunoscuta!"));

        close(pipefd[1]);
        exit(0);
      }
      else //parinte
      {
        close(pipefd[1]);
       // close(socket[0]);
        close(internal_pipe[1]);
        char rez[1000]="";
        read(internal_pipe[0],&LOGGED,sizeof(LOGGED));
        int read_rez=read(pipefd[0],rez,sizeof(rez)-1);
        if(read_rez>0){
          printf("Rezultatul comenzii: %s\n",rez);
          write(fd_resp,rez,strlen(rez));
        }
        close(pipefd[0]);
        close(internal_pipe[0]);
       // close(socket[1]);
        wait(NULL);
      }

    }
  } while (strcmp(s,"quit\n")!=0);
  close(fd);
 
  return 0;
}