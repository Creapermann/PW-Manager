#pragma once

#include "FtxuiIncludes.h"



class DatabaseManager 
{
private:
	const char* path{};

public:
	sqlite3* db{};


private:
	static int callback(void* data, int argc, char** argv, char** azColName);

public:
	bool initDB(const char* _sql);
	bool createTable(const char* _sql);
	bool insertIntoTable(const char* _sql);
	bool selectFromTable(const char* _sql);
	bool updateTable(const char* _sql);
	bool deleteFromTable(const char* _sql);
};