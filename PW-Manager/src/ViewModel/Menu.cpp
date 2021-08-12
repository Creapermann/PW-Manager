#include "Menu.h"

#include "../Model/DatabaseManager.h"
#include "../Model/User.h"

#include "../Model/CopyToClipboard.h"
#include "../Shared.h"

#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>




/// <summary>
/// Generates a random password based on certain settings
/// </summary>
void Menu::generatePassword()
{
	// Converts from wstring to int
	std::stringstream ss(std::string(generatedPasswordLength.begin(), generatedPasswordLength.end()));
	int length;
	ss >> length;
	ss.clear();


	// Error handling
	if (length <= 0 || length >= 100)
	{
		//TODO: Error handling password to long
		return;
	}


	std::vector<char> options{};
	
	// Adds possible characters to a vector based on settings
	if (lowercaseLetters)
	{
		// Adds all the chars from a-z
		for (int i = 97; i <= 122; i++)
		{
			options.emplace_back(static_cast<char>(i));
		}
	}
	if (uppercaseLetters)
	{
		// Adds all the chars from A-Z
		for (int i = 65; i <= 90; i++)
		{
			options.emplace_back(static_cast<char>(i));
		}
	}
	if (includeNumbers)
	{
		// Adds all numbers from 1-9 x2
		options.emplace_back('0');
		options.emplace_back('0');
		options.emplace_back('1');
		options.emplace_back('1');
		options.emplace_back('2');
		options.emplace_back('2');
		options.emplace_back('3');
		options.emplace_back('3');
		options.emplace_back('4');
		options.emplace_back('4');
		options.emplace_back('5');
		options.emplace_back('5');
		options.emplace_back('6');
		options.emplace_back('6');
		options.emplace_back('7');
		options.emplace_back('7');
		options.emplace_back('8');
		options.emplace_back('8');
		options.emplace_back('9');
		options.emplace_back('9');
	}
	if (includeSymbols)
	{
		options.emplace_back('~');
		options.emplace_back('!');
		options.emplace_back('@');
		options.emplace_back('#');
		options.emplace_back('$');
		options.emplace_back('%');
		options.emplace_back('^');
		options.emplace_back('*');
		options.emplace_back('(');
		options.emplace_back(')');
		options.emplace_back('-');
		options.emplace_back('_');
		options.emplace_back('+');
		options.emplace_back('=');
		options.emplace_back('{');
		options.emplace_back('}');
		options.emplace_back('[');
		options.emplace_back(']');
		options.emplace_back('/');
		options.emplace_back(':');
		options.emplace_back(';');
		options.emplace_back('<');
		options.emplace_back('>');
		options.emplace_back('.');
		options.emplace_back('?');
		options.emplace_back('"');
	}

	// Error handling
	if (options.size() <= 0)
	{
		//TODO: Error handling none of the boxes have been selected, at least 1 needs to be selected
		generatedPassword = L"";
		return;
	}

	// Generate a random password string by picking random indexes of the previously filled up vector of chars
	std::default_random_engine randomNumGenerator(time(0));
	std::uniform_int_distribution<int> rndm(0, options.size() - 1);

	std::string tempPW;

	for (int i = 0; i < length; i++)
	{	
		tempPW += options[rndm(randomNumGenerator)];
	}


	generatedPassword = std::wstring(tempPW.begin(), tempPW.end());
}


/// <summary>
/// Creates a new note
/// </summary>
void Menu::createNewNote()
{
	// Error Handling
	if (newNotePassword == L"" || newNoteTitle == L"")
	{
		// TODO: Not all needed data was provided
		return;
	}
	
	DatabaseManager dbm;

	DatabaseManager::selectedInfo.clear();

	// CHeck if the user already has a note with the same name
	std::string query = "SELECT TITLE FROM NOTES WHERE TITLE = '" + std::string(newNoteTitle.begin(), newNoteTitle.end()) + 
		"' AND PARENTID = '" + user.UserID + "'";
	dbm.selectFromTable(query);

	if (!DatabaseManager::selectedInfo.empty())
		return;

	DatabaseManager::selectedInfo.clear();



	// Create/Open table
	dbm.createTable("CREATE TABLE IF NOT EXISTS NOTES("
		"PARENTID       TEXT          NOT NULL, "
		"TITLE          TEXT		  NOT NULL  "
		"USERNAME       TEXT          NOT NULL, "
		"EMAIL          TEXT		  NOT NULL, "
		"PASSWORD       TEXT		  NOT NULL, "
		"DESCRIPTION    TEXT          NOT NULL); "
	);

	// Insert the note into the db and checks if the insertion was sucessfull
	if (dbm.insertIntoTable("INSERT INTO NOTES (PARENTID, TITLE, USERNAME, EMAIL, PASSWORD, DESCRIPTION) "
		"VALUES"
		"("
		"'" + user.UserID + "', "
		"'" + std::string(newNoteTitle.begin(), newNoteTitle.end()) + "', "
		"'" + std::string(newNoteUsername.begin(), newNoteUsername.end()) + "', "
		"'" + std::string(newNoteEmail.begin(), newNoteEmail.end()) + "', "
		"'" + std::string(newNotePassword.begin(), newNotePassword.end()) + "', "
		"'" + std::string(newNoteDescription.begin(), newNoteDescription.end()) + "'"
		" );"))
	{
		// Adds the newly added note to the users note vector
		getUserNotes();
	}
	else
	{
		// Error Handling note with the same name does already exist
	}

	

	DatabaseManager::selectedInfo.clear();
}


/// <summary>
/// Gets all the existing notes of the user and pushes them back into a vector
/// </summary>
std::vector<std::wstring> Menu::getUserNotes()
{
	// Creates the datatable if it doesnt exist
	DatabaseManager dbm;
	dbm.createTable("CREATE TABLE IF NOT EXISTS NOTES("
		"PARENTID       TEXT          NOT NULL, "
		"TITLE          TEXT		  NOT NULL, "
		"USERNAME       TEXT          NOT NULL, "
		"EMAIL          TEXT		  NOT NULL, "
		"PASSWORD       TEXT		  NOT NULL, "
		"DESCRIPTION    TEXT          NOT NULL); "
	);

	DatabaseManager::selectedInfo.clear();


	// Gets all the names of the notes
	dbm.selectFromTable("SELECT TITLE from NOTES WHERE PARENTID='" + user.UserID + "'");
	std::vector<std::wstring> tempNamesVec;
	
	// Pushes all the notes back into a vector
	for (auto s : DatabaseManager::selectedInfo) 
	{
		tempNamesVec.emplace_back(s.begin(), s.end());
	}


	// Makes Note objects from the names and push it into a vector
	for (std::wstring title : tempNamesVec)
	{
		DatabaseManager::selectedInfo.clear();
		dbm.selectFromTable("SELECT * from NOTES WHERE TITLE='" + std::string(title.begin(), title.end()) + "'");

		Note note;
		note.parentID	 = std::wstring(DatabaseManager::selectedInfo[0].begin(), DatabaseManager::selectedInfo[0].end());
		note.title       = std::wstring(DatabaseManager::selectedInfo[1].begin(), DatabaseManager::selectedInfo[1].end());
		note.username    = std::wstring(DatabaseManager::selectedInfo[2].begin(), DatabaseManager::selectedInfo[2].end());
		note.email       = std::wstring(DatabaseManager::selectedInfo[3].begin(), DatabaseManager::selectedInfo[3].end());
		note.password    = std::wstring(DatabaseManager::selectedInfo[4].begin(), DatabaseManager::selectedInfo[4].end());
		note.description = std::wstring(DatabaseManager::selectedInfo[5].begin(), DatabaseManager::selectedInfo[5].end());

		userNotes.emplace_back(std::move(note));
	}


	return tempNamesVec;
}