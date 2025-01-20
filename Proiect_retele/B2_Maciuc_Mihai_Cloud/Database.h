#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;
class Database
{
     private:
    sqlite3* db;
    Database* backup_db;
    public:
    Database(const string& dbFile);
    ~Database();

    void initializare();
    void uploadFile(const string& fileName,const string& filePath);
    vector<string> listFIles();
    void deleteFile(const string& fileName);
    string getFilePath(const string& fileName);
    void setBackup(Database* backup_db);
   
};
#endif