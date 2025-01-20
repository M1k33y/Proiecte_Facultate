#include "Database.h"
#include <iostream>
#include <stdexcept>

using namespace std;
Database::Database(const string& dbFile)
{
  if(sqlite3_open(dbFile.c_str(),&db))
    throw runtime_error("Failed to open the database!");
    //.c_str() face un pointer de tip const string
}

Database::~Database()
{
    sqlite3_close(db);
}

void Database::setBackup(Database* backup_db)
{
    this->backup_db=backup_db;
}


void Database::initializare()
{
    const char* createTable = R"(CREATE TABLE IF NOT EXISTS Files
        (id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL UNIQUE,
        file_path TEXT NOT NULL);
        )";
char* errorMsg=nullptr;
    if(sqlite3_exec(db,createTable,nullptr,nullptr,&errorMsg)!=SQLITE_OK) //db,sql comm,callback func, arg callback, errmsg
        {
            string error="Failed to create table"+ string(errorMsg);
            sqlite3_free(errorMsg);
            throw runtime_error(error);
        }
        else
        {
            cout<<"Tabela a fost creeata deja sau exista!"<<endl;
        }
}
void Database::uploadFile(const string& fileName,const string& filePath)
{
    //verific daca am fisierul deja
    const char* checkInSQL="SELECT COUNT(*) FROM Files WHERE name=? AND file_path=?;";
    sqlite3_stmt*checkstmt;

    if(sqlite3_prepare_v2(db,checkInSQL,-1,&checkstmt,nullptr)!=SQLITE_OK)
    {
        cerr<<"Failed to prepare check statement "<<sqlite3_errmsg(db)<<endl;
        return; 
    }
    sqlite3_bind_text(checkstmt,1,fileName.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(checkstmt,2,filePath.c_str(),-1,SQLITE_STATIC);

    int exista=0;
    if(sqlite3_step(checkstmt)==SQLITE_ROW)
        exista=sqlite3_column_int(checkstmt,0);

    sqlite3_finalize(checkstmt);

    if(exista>0)
    {
        cout<<"Fisierul "<<fileName<<"exista deja in bd";
        return;
    }

    //daca nu apare il adaug
    const char* insertInSQL= "INSERT INTO Files (name,file_path) VALUES (?,?);";
    sqlite3_stmt* stmt;

    if(sqlite3_prepare_v2(db,insertInSQL,-1,&stmt,nullptr)!=SQLITE_OK)
        throw runtime_error("Failed to prepare statement");

    cout<<"Se adauga nume= "<<fileName<<" cale= "<<filePath<<endl;
    sqlite3_bind_text(stmt,1,fileName.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt,2,filePath.c_str(),-1,SQLITE_STATIC);

    if(sqlite3_step(stmt)!=SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        throw runtime_error("Failed to execute statement");
    }
    else
    {
        cout<<"Fisier adaugat in db: "<<fileName<<"->"<<filePath<<endl;
    }
    sqlite3_finalize(stmt);

    //sincronizare cu backup
    if(backup_db)
    {
        try
        {
            backup_db->uploadFile(fileName,filePath);
        }
        catch(const exception& e)
        {
            cerr <<"Eroare la sincronizare"<< e.what() <<endl;
        }
        
    }
}
vector<string> Database::listFIles()
{
    const char* selectInSQL="SELECT name FROM Files;";
    sqlite3_stmt* stmt;
    vector<string> files;

    if(sqlite3_prepare_v2(db,selectInSQL,-1,&stmt,nullptr)!=SQLITE_OK)
        {
            cerr<<"Failed to prepare SELECT statement: "<<sqlite3_errmsg(db)<<endl;
            return files;
        }
    
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        files.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0)));
    }
    sqlite3_finalize(stmt);
    return files;
}
void Database::deleteFile(const string& fileName)
{
    const char* deleteInSQL="DELETE FROM Files WHERE name=?;";
    sqlite3_stmt* stmt;

    if(sqlite3_prepare_v2(db,deleteInSQL,-1,&stmt,nullptr)!=SQLITE_OK)
        throw runtime_error("Failed to prepare statement");

    sqlite3_bind_text(stmt,1,fileName.c_str(),-1,SQLITE_STATIC);

    if(sqlite3_step(stmt)!=SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        throw runtime_error("Failed to execute statement");
    }
    sqlite3_finalize(stmt);

    if(backup_db)
    {
        try
        {
            backup_db->deleteFile(fileName);
        }
        catch(const exception& e)
        {
            cerr << "Eroare la sincronizare"<<e.what() << '\n';
        }
        
    }
}

string Database::getFilePath(const string& fileName)
{
    const char* selectInSQL="SELECT file_path from Files WHERE name=?;";
    sqlite3_stmt* stmt;

    if(sqlite3_prepare_v2(db,selectInSQL,-1,&stmt,nullptr)!=SQLITE_OK)
    {
        cerr<<"Failed to prepare statement: "<<sqlite3_errmsg(db)<<endl;
        return "";
    }
    sqlite3_bind_text(stmt,1,fileName.c_str(),-1,SQLITE_STATIC);

    string path;
    if(sqlite3_step(stmt)==SQLITE_ROW)
    path=reinterpret_cast<const char*>(sqlite3_column_text(stmt,0));
    else 
    {
        cerr<<"File not found in db: "<<fileName<<endl;
    }

    sqlite3_finalize(stmt);
    return path;

}