#include "Signup.h"
#include "UI_Login.h"
#include "DatabaseManager.h"

#include <algorithm>


bool contains(const std::wstring& str, char c)
{
	for (char i : str)
	{
		if (i == c)
			return true;
	}

	return false;
}

/// <summary>
/// Signs up the user with provided data
/// </summary>
void Signup::signupButtonClick(std::wstring& e_first)
{
	if (firstname.length() < 3)
	{
		e_first = L"Your firstname needs to be at least 3 characters long";
		return;
	}

	if (lastname.length() < 3)
	{
		e_first = L"Your lastname needs to be at least 3 characters long";
		return;
	}

	if (email.length() < 6 || !contains(email, '@') || !contains(email, '.'))
	{
		e_first = L"Your email is invalid";
		return;
	}

	if (password.length() < 6)
	{
		e_first = L"Your password needs to be at least 6 characters long";
		return;
	}

	if (password != confirmPassword)
	{
		e_first = L"Your passwords do not match";
		return;
	}


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
		e_first = L"An email with this account already exists";
		return;
	}
	
}

void Signup::menuButtonClick() { showStartWindow(); }

