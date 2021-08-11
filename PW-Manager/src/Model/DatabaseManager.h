#pragma once

#include "FtxuiIncludes.h"
#include "sqlite3.h"



class DatabaseManager
{
public:
	bool initDB(std::string _sql);
	bool createTable(std::string _sql);
	bool insertIntoTable(std::string _sql);
	bool selectFromTable(std::string _sql);
	bool updateTable(std::string _sql);
	bool deleteFromTable(std::string _sql);

	const std::string path{ "./DontDelete/Passwords.db" };
	const std::string folderName{ "./DontDelete/" };
	
	static inline std::vector<std::string> selectedInfo;


private:
	static int callback(void* data, int argc, char** argv, char** azColName);
	sqlite3* db{};


};