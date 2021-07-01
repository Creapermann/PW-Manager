//#include "DatabaseManager.h"
//
//
//int DatabaseManager::callback(void* data, int argc, char** argv, char** azColName)
//{
//	int i;
//
//	for (i = 0; i < argc; i++)
//	{
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//
//	printf("\n");
//	return 0;
//}
//
///// <summary>
///// Connect to the database, if no dabatbase with the given name exists, create a new one
///// </summary>
//bool DatabaseManager::initDB(const char* _path)
//{
//	// Setting variables on initialisation
//	path = _path;
//
//
//	char* zErrMsg = 0;
//	int rc{};
//
//	rc = sqlite3_open(path, &db);   // If no database with the given name exists, a new one gets created
//
//	if (rc != SQLITE_OK)
//	{						 // Checks if the to the db was sucessfull
//		sqlite3_close(db);
//		return false;
//	}
//
//	//sqlite3_close(db);				 // Closes the connection
//}
//
///// <summary>
///// Create a table with the given query
///// </summary>
//bool DatabaseManager::createTable(const char* _sql)
//{
//	int rc{};
//	char* zErrMsg;
//
//	rc = sqlite3_open(path, &db);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//	rc = sqlite3_exec(db, _sql, NULL, 0, &zErrMsg);
//
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//	sqlite3_close(db);
//}
//
///// <summary>
///// Insert given elements by the query into the table
///// </summary>
//bool DatabaseManager::insertIntoTable(const char* _sql)
//{
//	int rc{};
//	char* zErrMsg = 0;
//
//	sqlite3_open(path, &db);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//
//	rc = sqlite3_exec(db, _sql, NULL, 0, &zErrMsg);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//	sqlite3_close(db);
//}
//
///// <summary>
///// Read given elements by the query from the table
///// </summary>
//bool DatabaseManager::selectFromTable(const char* _sql)
//{
//	int rc{};
//	char* zErrMsg = 0;
//	const char* data{};
//
//	sqlite3_open(path, &db);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//
//	rc = sqlite3_exec(db, _sql, callback, (void*)data, &zErrMsg);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//	sqlite3_close(db);
//}
//
///// <summary>
///// Update given elements by the query from the table
///// </summary>
//bool DatabaseManager::updateTable(const char* _sql)
//{
//	int rc{};
//	char* zErrMsg = 0;
//
//	sqlite3_open(path, &db);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//
//	rc = sqlite3_exec(db, _sql, NULL, 0, &zErrMsg);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//	sqlite3_close(db);
//}
//
///// <summary>
///// Delete given elements by the query from the table
///// </summary>
//bool DatabaseManager::deleteFromTable(const char* _sql)
//{
//	int rc{};
//	char* zErrMsg = 0;
//
//	sqlite3_open(path, &db);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//
//	rc = sqlite3_exec(db, _sql, NULL, 0, &zErrMsg);
//
//	if (rc != SQLITE_OK)
//	{
//		sqlite3_close(db);
//		return false;
//	}
//
//	sqlite3_close(db);
//}
