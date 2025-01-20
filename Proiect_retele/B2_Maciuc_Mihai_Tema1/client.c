    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    #define FIFO_NAME "MyTest_FIFO"
    #define FIFO_RESP "ServerToClient_Fifo"
    int main()
    {
        char s[300];
        int num, fd,fd_resp;
      

        printf("Astept cititori...\n");
        fd = open(FIFO_NAME, O_WRONLY);
        fd_resp=open(FIFO_RESP,O_RDONLY);
        printf("Am un cititor.....\n");
        printf("Introduceti comanda:\n");
        while (fgets(s, sizeof(s), stdin), !feof(stdin)) {
            
            if ((num = write(fd, s, strlen(s))) == -1)
                perror("Problema la scriere in FIFO!");
            else
                printf("S-au scris in FIFO %d bytes\n", num);

        //raspuns server
        char resp[1000];
        if((num = read(fd_resp,resp,1000))>0){
            resp[num]='\0'; //sa se termine corect
            printf("Raspuns server: %s\n",resp);

        }else
        {
            perror("eroare la citire fifo");
        }
        
        }
        close(fd);
        close(fd_resp);
        return 0;
    }
