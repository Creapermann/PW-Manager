#include "Signup.h"
#include "./View/UI_Login.h"
#include "Model/DatabaseManager.h"


/// <summary>
/// Signs up the user with provided data
/// </summary>
void Signup::signupButtonClick()
{
	if (firstname.length() >= 2 && email.length() >= 4 && password.length() >= 6 && password == confirmPassword)
	{

		// Create database if it does not exist
		DatabaseManager dbm;
		dbm.createTable("CREATE TABLE IF NOT EXISTS USERS("
		"ID INTEGER     PRIMARY KEY   AUTOINCREMENT, "
		"FIRSTNAME      TEXT		  NOT NULL, "
		"LASTNAME       TEXT		  NOT NULL, "
		"EMAIL          TEXT		  NOT NULL          UNIQUE, "
		"PASSWORD       TEXT		  NOT NULL );"
		);
		

		// Insert into db
		if (dbm.insertIntoTable("INSERT INTO USERS (FIRSTNAME, LASTNAME, EMAIL, PASSWORD) "
			"VALUES"
			"("
			"'" + std::string(firstname.begin(), firstname.end()) + "', "
			"'" + std::string(lastname.begin(), lastname.end()) + "', "
			"'" + std::string(email.begin(), email.end()) + "', "
			"'" + std::string(password.begin(), password.end()) + "'"
			" );"))
		{
			showLoginWindow();
		}
		else
		{
			//TODO: Error Handling, account with this email already exists
			return;
		}
	}
}

void Signup::menuButtonClick() { showStartWindow(); }

