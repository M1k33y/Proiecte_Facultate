#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <vector>
#include <thread>
#include <fstream>
#include <arpa/inet.h>
using namespace std;
#define server_ip "127.0.0.1"
#define port 8080
#define dim 1024

void upload_file(int sd, char *file)
{
    char mesaj[dim];
    snprintf(mesaj, sizeof(mesaj), "UPLOAD %s\n", file);
    write(sd, mesaj, strlen(mesaj));

    ifstream inFile(file, ios::binary);
    if (!inFile)
    {
        cerr << "Fisierul nu poate fi deschis: " << file << endl;
        return;
    }
    char fileBuffer[dim];
    while (inFile.read(fileBuffer, dim) || inFile.gcount() > 0)
    {
        write(sd, fileBuffer, inFile.gcount());
        //gcount nr caractere citite la ultima operatie de citire pe fisier
    }
    inFile.close();

    // fac un marker de sf fisier
    memset(fileBuffer, 0, dim);
    write(sd, fileBuffer, sizeof(fileBuffer));
    cout << "Fisierul trimis: " << file << endl;
}
void download_file(int sd, char *file)
{
    char mesaj[dim];
    snprintf(mesaj, sizeof(mesaj), "DOWNLOAD %s\n", file);
    write(sd, mesaj, strlen(mesaj));

    // fac fisier pentru salvare date primite
    ofstream outFile(file, ios::binary);

    if (!outFile)
    {
        cerr << "Eroare la crearea fisierului pt download" << file << endl;
        return;
    }

    char fileBuffer[dim];
    int bytesReceived;

    while (true)
    {
        memset(fileBuffer, 0, dim);
        bytesReceived = read(sd, fileBuffer, dim);

        if (bytesReceived <= 0 || (bytesReceived == dim && memcmp(fileBuffer, "\0", dim) == 0))
            break;
        outFile.write(fileBuffer, bytesReceived);
        if (bytesReceived < dim)
            break;
    }
    outFile.close();
    cout << "Fisierul " << file << " a fost descarcat cu succes" << endl;
}
void list_file(int sd, char *file)
{
    char *mesaj = "LIST\n";
    write(sd, mesaj, strlen(mesaj));

    char buffer[dim];
    string fullResp;
    while (true)
    {
        memset(buffer, 0, dim);
        int bytesReceived = read(sd, buffer, dim);

        if (bytesReceived <= 0)
        {
            cout << "Eroare la primirea listei de fisiere de la server\n";
            return;
        }
        fullResp+=buffer;
        if(fullResp.find("END_OF_LIST")>=0)
        {
            fullResp=fullResp.substr(0,fullResp.find("END_OF_LIST"));
            break;
        }
    }
    cout<<fullResp<<endl;

}
void delete_file(int sd, char *file)
{
    char mesaj[dim];
    snprintf(mesaj, sizeof(mesaj), "DELETE %s\n", file);
    cout << "Trimis comanda: " << mesaj << endl;
    write(sd, mesaj, strlen(mesaj));
    cout << "S-a sters fisierul: " << file << endl;
}
int main()
{
    int sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd < 0)
    {
        perror("Eroare la creare socket client");
        return 1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_port = htons(port);

    if (connect(sd, (struct sockaddr *)&server, sizeof(sockaddr)) < 0)
    {
        perror("Eroare la conectare client");
        return 1;
    }

    cout << "\n------WELCOME TO MY PERSONAL CLOUD STORAGE------              \n\n";

    cout << "****************************\n"
         << "****************************\n"
         << "** 1- Upload File         **\n"
         << "** 2- Download File       **\n"
         << "** 3- List File           **\n"
         << "** 4- Delete File         **\n"
         << "** 5- Exit                **\n"
         << "****************************\n"
         << "****************************\n";

    
    while (true)
    {

        char choice[20] = "";
        cin.getline(choice, 20);
        char file[256] = "";

        if (strcmp(choice, "Upload") == 0)
        {
            cout << "Scrieti numele fisierului: ";
            cin >> file;
            upload_file(sd, file);
           
        }
        else if (strcmp(choice, "Download") == 0)
        {
            cout << "Scrieti numele fisierului: ";
            cin >> file;
            download_file(sd, file);
        }
        else if (strcmp(choice, "Exit") == 0)
        {
            close(sd);
            return 0;
        }
        else if (strcmp(choice, "Delete") == 0)
        {
            cout << "Scrieti numele fisierului: ";
            cin >> file;
            delete_file(sd, file);
        }
        else if (strcmp(choice, "List") == 0)
        {

            list_file(sd, file);
        }
        else if (strcmp(choice, "") != 0)
        {
            cout << "Optiunea introdusa este invalida!" << endl;
        }
    }
}