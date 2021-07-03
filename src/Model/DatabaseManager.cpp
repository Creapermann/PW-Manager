#include "DatabaseManager.h"


int DatabaseManager::callback(void* data, int argc, char** argv, char** azColName)
{
	int i;

	DatabaseManager::selectedInfo.clear();

	for (i = 0; i < argc; i++)
	{
		DatabaseManager::selectedInfo.emplace_back(argv[i]);         //
	}

	return 0;
}

/// <summary>
/// Connect to the database, if no dabatbase with the given name exists, create a new one
/// </summary>
bool DatabaseManager::initDB(std::string _path)
{
	char* zErrMsg = 0;
	int rc;

	rc = sqlite3_open(path.c_str(), &db);   // If no database with the given name exists, a new one gets created

	if (rc != SQLITE_OK)
	{						 // Checks if the to the db was sucessfull
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);				 // Closes the connection
	return true;
}

/// <summary>
/// Create a table with the given query
/// </summary>
bool DatabaseManager::createTable(std::string _sql)
{
	int rc{};
	char* zErrMsg;

	rc = sqlite3_open(path.c_str(), &db);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	rc = sqlite3_exec(db, _sql.c_str(), callback, 0, &zErrMsg);


	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);

	return true;
}

/// <summary>
/// Insert given elements by the query into the table
/// </summary>
bool DatabaseManager::insertIntoTable(std::string _sql)
{
	int rc{};
	char* zErrMsg = 0;

	sqlite3_open(path.c_str(), &db);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}


	rc = sqlite3_exec(db, _sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);

	return true;
}

/// <summary>
/// Read given elements by the query from the table
/// </summary>
bool DatabaseManager::selectFromTable(std::string _sql)
{
	int rc{};
	char* zErrMsg = 0;
	std::string data{};

	sqlite3_open(path.c_str(), &db);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}


	rc = sqlite3_exec(db, _sql.c_str(), callback, (void*)data.c_str(), &zErrMsg);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);

	if (selectedInfo.empty())   // It returns false, no data could be selected
		return false;
	return true;
}

/// <summary>
/// Update given elements by the query from the table
/// </summary>
bool DatabaseManager::updateTable(std::string _sql)
{
	int rc{};
	char* zErrMsg = 0;

	sqlite3_open(path.c_str(), &db);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}


	rc = sqlite3_exec(db, _sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);

	return true;
}

/// <summary>
/// Delete given elements by the query from the table
/// </summary>
bool DatabaseManager::deleteFromTable(std::string _sql)
{
	int rc{};
	char* zErrMsg = 0;

	sqlite3_open(path.c_str(), &db);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}


	rc = sqlite3_exec(db, _sql.c_str(), NULL, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);
	return true;
}
