#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <vector>
#include <thread>

#include "Database.h"
#define nr_clienti 10
#define port 8080
#define dim 1024
using namespace std;



string vigenere_encription(string text,string key)
{
    string rez;
    int lg=key.length();

    for(int i=0;i<text.length();i++)
    {
        char caracter= ((text[i]-' ') +(key[i%lg]-' '))%256+' ';
        //daca lucram doar cu litere scadeam 'a' pt ca am orice ascii scad ' '
        //la sf adun ' ' sa iau caract
        rez+=caracter;
    }
    return rez;
}

string vigenere_decription(string text,string key)
{
    string rez;
    int lg=key.length();

    for(int i=0;i<text.length();i++)
    {
        char caracter= ((text[i]-' ') -(key[i%lg]-' ')+256)%256+' ';
       //adun 256 ca sa nu am pericol de nr negative
        rez+=caracter;
    }
    return rez;
}


void handle_client(int client_sd, Database &database, Database &database_backup)
{
    char buffer[dim];
    while (true)
    {
        // reinitializez bufferu
        memset(buffer, 0, dim);
        int primit = read(client_sd, buffer, dim);
        if (primit <= 0)
        {
            cout << "Client deconectat " << client_sd << endl;
            break;
        }
        cout << "Comanda primita: ";
        try{
        if (strncmp(buffer, "UPLOAD", 6) == 0)
        {
            

            char fileName[256];
            sscanf(buffer + 7, "%s", fileName); // citesc fisierul

            // fac pathul
            string filePath = "./files/";
            filePath += fileName;

            // daca exista
            ifstream existFile(filePath,ios::binary);
            if(existFile.is_open())
            {
                cout<<"Fisierul exista deja. Upload ignorat\n";
                existFile.close();
                return;
            }


            ofstream outFile(filePath, ios::binary);
            if (outFile)
            {
                char fileBuffer[dim]; // iau chunks de file data
                int bytesReceived;

                while (true)
                {
                    memset(fileBuffer, 0, dim);
                    bytesReceived = read(client_sd, fileBuffer, dim);

                    if (bytesReceived <= 0 || (bytesReceived == dim && memcmp(fileBuffer, "\0", dim) == 0))
                        break;
                    outFile.write(fileBuffer, bytesReceived);
                    if (bytesReceived < dim)
                        break;
                }
                outFile.close();
                database.uploadFile(fileName, filePath);
                cout << "fisierul " << fileName << " UPLOADAT " << endl;
            }
            else
            {
                cerr << "Eroare la crearea fisierului pe sv\n";
            }
        }
        else if (strncmp(buffer, "DOWNLOAD", 8) == 0)
        {
            // trimite fisier

            char fileName[256];
            sscanf(buffer + 9, "%s", fileName);

            string filePath = database.getFilePath(fileName);
            if (!filePath.empty())
            {
                ifstream inFile(filePath, ios::binary);
                if (inFile)
                {
                    char fileBuffer[dim];
                    while (inFile.read(fileBuffer, dim))
                    {
                        write(client_sd, fileBuffer, inFile.gcount());
                    }

                    if(inFile.gcount()>0)
                        write(client_sd,fileBuffer,inFile.gcount());

                    //trimit un buffer gol ca sa termine transferu
                    memset(fileBuffer,0,dim);
                    write(client_sd,fileBuffer,dim);

                    inFile.close();
                    cout << "Fisierul trimis: " << fileName << endl;
                }
                else
                {
                cerr<<"Eroare la deschidere fisier\n";
                }
            }
            else{
                cerr << "Fisierul nu s-a gasit in bd\n";
            }
            

            cout << "fisier DOWNLOADAT " << endl;
        }
        else if (strncmp(buffer, "DELETE", 6) == 0)
        {
            // trimite fisier
            char fileName[256];
            sscanf(buffer+7,"%s",fileName);

            string filePath=database.getFilePath(fileName);
            if(!filePath.empty())
            {

                if(remove(filePath.c_str())==0) //0 pt succesful -1 la fail fisierul de pe disc
                {
                    database.deleteFile(fileName); //sterge fisierul din bd
                    cout << "fisier sters" << endl;
                }
                else
                    cerr<<"eroare la stergerea fisierului\n";
            }
            else 
            cerr<<"Fisierul nu apare in baza de date\n";

        }
        else if (strncmp(buffer, "LIST", 4) == 0)
        {
            // trimite fisier
            vector<string> files=database.listFIles();
            string response;
            if(files.empty())
            response="Nu exista fisiere in spatiul dumneavoastra:)";
            else{
            response="Fisiere disponibile:\n";
            for(auto file: files)
                response+=file+'\n';
            
            }
            response+="END_OF_LIST"; //terminatoru
            write(client_sd,response.c_str(),response.size());
            cout << "fisierele sunt listate" << endl;
        }
        }catch(const exception& e)
        {
            cerr<<"Eroare la baza de date principala "<<e.what()<<endl;

            //fac aceleasi chestii dar pe cealalta baza

            if (strncmp(buffer, "UPLOAD", 6) == 0)
        {
            

            char fileName[256];
            sscanf(buffer + 7, "%s", fileName); // citesc fisierul

            // fac pathul
            string filePath = "./files/";
            filePath += fileName;

            // daca exista
            ifstream existFile(filePath,ios::binary);
            if(existFile.is_open())
            {
                cout<<"Fisierul exista deja. Upload ignorat\n";
                existFile.close();
                return;
            }


            ofstream outFile(filePath, ios::binary);
            if (outFile)
            {
                char fileBuffer[dim]; // iau chunks de file data
                int bytesReceived;

                while (true)
                {
                    memset(fileBuffer, 0, dim);
                    bytesReceived = read(client_sd, fileBuffer, dim);

                    if (bytesReceived <= 0 || (bytesReceived == dim && memcmp(fileBuffer, "\0", dim) == 0))
                        break;
                    outFile.write(fileBuffer, bytesReceived);
                    if (bytesReceived < dim)
                        break;
                }
                outFile.close();
                database_backup.uploadFile(fileName, filePath);
                cout << "fisierul " << fileName << " UPLOADAT " << endl;
            }
            else
            {
                cerr << "Eroare la crearea fisierului pe sv\n";
            }
        }
        else if (strncmp(buffer, "DOWNLOAD", 8) == 0)
        {
            // trimite fisier

            char fileName[256];
            sscanf(buffer + 9, "%s", fileName);

            string filePath = database.getFilePath(fileName);
            if (!filePath.empty())
            {
                ifstream inFile(filePath, ios::binary);
                if (inFile)
                {
                    char fileBuffer[dim];
                    while (inFile.read(fileBuffer, dim))
                    {
                        write(client_sd, fileBuffer, inFile.gcount());
                    }

                    if(inFile.gcount()>0)
                        write(client_sd,fileBuffer,inFile.gcount());

                    //trimit un buffer gol ca sa termine transferu
                    memset(fileBuffer,0,dim);
                    write(client_sd,fileBuffer,dim);

                    inFile.close();
                    cout << "Fisierul trimis: " << fileName << endl;
                }
                else
                {
                cerr<<"Eroare la deschidere fisier\n";
                }
            }
            else{
                cerr << "Fisierul nu s-a gasit in bd\n";
            }
            

            cout << "fisier DOWNLOADAT " << endl;
        }
        else if (strncmp(buffer, "DELETE", 6) == 0)
        {
            // trimite fisier
            char fileName[256];
            sscanf(buffer+7,"%s",fileName);

            string filePath=database_backup.getFilePath(fileName);
            if(!filePath.empty())
            {

                if(remove(filePath.c_str())==0) //0 pt succesful -1 la fail fisierul de pe disc
                {
                    database.deleteFile(fileName); //sterge fisierul din bd
                    cout << "fisier sters" << endl;
                }
                else
                    cerr<<"eroare la stergerea fisierului\n";
            }
            else 
            cerr<<"Fisierul nu apare in baza de date\n";

        }
        else if (strncmp(buffer, "LIST", 4) == 0)
        {
            // trimite fisier
            vector<string> files=database_backup.listFIles();
            string response;
            if(files.empty())
            response="Nu exista fisiere in spatiul dumneavoastra:)";
            else{
            response="Fisiere disponibile:\n";
            for(auto file: files)
                response+=file+'\n';
            
            }
            response+="END_OF_LIST"; //terminatoru
            write(client_sd,response.c_str(),response.size());
            cout << "fisierele sunt listate" << endl;
        }

        }
    }
    close(client_sd);
}

int main()
{
    Database database("files.db");
    Database database_backup("files_backup.db");

    database.initializare();
    database_backup.initializare();

    cout<<"Sincronizare initiala..."<<endl;
    vector<string>files=database.listFIles();
    for(string file :files)
    {
        string filePath=database.getFilePath(file);
        database_backup.uploadFile(file,filePath);
    }
    cout<<"Gata sincronizarea"<<endl;
    

    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0)
    {
        perror("Eroare la creare socket server");
        return 1;
    }

    struct sockaddr_in server;

    // setez structura de socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);

    int flag = 1;
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &flag, sizeof(flag)) < 0)
    {
        perror("eroare la optiuni socket");
        return 1;
    }

    if (bind(sd, (struct sockaddr *)&server, sizeof(sockaddr)) < 0)
    {
        perror("Eroare la bind");
        return 1;
    }

    if (listen(sd, 5) < 0)
    {
        perror("Eroare la listen");
        return 1;
    }

    while (true)
    {
        int client_sd = accept(sd, NULL, NULL);
        if (client_sd < 0)
        {
            perror("Eroare la accept");
            continue;
        }
        cout << "Client nou: " << client_sd << endl;
        thread(handle_client, client_sd, ref(database),ref(database_backup)).detach();
        // thread clientThread(handle_client,client_sd);
        // clientThread.detach();
        
    }
    return 0;
}
