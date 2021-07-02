#include "Signup.h"
#include "./View/UI_Login.h"
#include "Model/DatabaseManager.h"


void Signup::signupButtonClick(std::wstring firstname, std::wstring lastname, std::wstring email, std::wstring password, std::wstring confirmPassword)
{
	if (firstname.length() >= 2 && email.length() >= 4 && password.length() >= 6 && password == confirmPassword)
	{
		// Create database if it does not exist
		DatabaseManager dbm;
		dbm.createTable("CREATE TABLE IF NOT EXISTS USERS("
		"ID INTEGER     PRIMARY KEY   AUTOINCREMENT, "
		"FIRSTNAME      TEXT		  NOT NULL, "
		"LASTNAME       TEXT		  NOT NULL, "
		"EMAIL          TEXT		  NOT NULL, "
		"PASSWORD       TEXT		  NOT NULL );"
		);
		

		// Insert into db
		dbm.insertIntoTable("INSERT INTO USERS (FIRSTNAME, LASTNAME, EMAIL, PASSWORD) "
							"VALUES"
							"(" 
							"'" + std::string(firstname.begin(), firstname.end()) + "', "
							"'" + std::string(lastname.begin(), lastname.end())   + "', "
							"'" + std::string(email.begin(), email.end())		  + "', "
							"'" + std::string(password.begin(), password.end())	  + "'"
							" );");

		showLoginWindow();
	}
}

void Signup::menuButtonClick() { showStartWindow(); }

