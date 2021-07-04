#include "Menu.h"

#include "../Model/DatabaseManager.h"
#include "../Model/User.h"
#include "clip/clip.h"
#include <cassert>
#include <string>

#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <ctime>


extern User user;


void Menu::generatePassword()
{
	// Converts from wstring to int
	std::stringstream ss(std::string(generatedPasswordLength.begin(), generatedPasswordLength.end()));
	int length;
	ss >> length;
	ss.clear();

	if (length <= 0 || length >= 1000)
	{
		generatedPassword = L"";
		return;
	}

	std::vector<char> options{};

	if (lowercaseLetters)
	{
		options.emplace_back('a');
		options.emplace_back('b');
		options.emplace_back('c');
		options.emplace_back('d');
		options.emplace_back('e');
		options.emplace_back('f');
		options.emplace_back('g');
		options.emplace_back('h');
		options.emplace_back('i');
		options.emplace_back('j');
		options.emplace_back('k');
		options.emplace_back('l');
		options.emplace_back('m');
		options.emplace_back('n');
		options.emplace_back('o');
		options.emplace_back('p');
		options.emplace_back('q');
		options.emplace_back('r');
		options.emplace_back('s');
		options.emplace_back('t');
		options.emplace_back('u');
		options.emplace_back('v');
		options.emplace_back('w');
		options.emplace_back('x');
		options.emplace_back('y');
		options.emplace_back('z');
	}
	if (uppercaseLetters)
	{
		options.emplace_back('A');
		options.emplace_back('B');
		options.emplace_back('C');
		options.emplace_back('D');
		options.emplace_back('E');
		options.emplace_back('F');
		options.emplace_back('G');
		options.emplace_back('H');
		options.emplace_back('I');
		options.emplace_back('J');
		options.emplace_back('K');
		options.emplace_back('L');
		options.emplace_back('M');
		options.emplace_back('N');
		options.emplace_back('O');
		options.emplace_back('P');
		options.emplace_back('Q');
		options.emplace_back('R');
		options.emplace_back('S');
		options.emplace_back('T');
		options.emplace_back('U');
		options.emplace_back('V');
		options.emplace_back('W');
		options.emplace_back('X');
		options.emplace_back('Y');
		options.emplace_back('Z');
	}
	if (includeNumbers)
	{
		options.emplace_back('0');
		options.emplace_back('1');
		options.emplace_back('2');
		options.emplace_back('3');
		options.emplace_back('4');
		options.emplace_back('5');
		options.emplace_back('6');
		options.emplace_back('7');
		options.emplace_back('8');
		options.emplace_back('9');
		options.emplace_back('0');
		options.emplace_back('1');
		options.emplace_back('2');
		options.emplace_back('3');
		options.emplace_back('4');
		options.emplace_back('5');
		options.emplace_back('6');
		options.emplace_back('7');
		options.emplace_back('8');
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


	std::default_random_engine randomNumGenerator(time(0));
	std::uniform_int_distribution<int> rndm(0, options.size() - 1);

	std::string tempPW;
	
	for (int i = 0; i < length; i++)
	{	
		tempPW += options[rndm(randomNumGenerator)];
	}

	generatedPassword = std::wstring(tempPW.begin(), tempPW.end());
}

void Menu::copyPasswordToClipboard()
{
	clip::set_text(std::string(generatedPassword.begin(), generatedPassword.end()));
}



void Menu::createNewNote()
{
	DatabaseManager dbm;

	// Gets all Notes of the user
	dbm.selectFromTable("SELECT TITLE from NOTES WHERE PARENTID='" + user.UserID + "'");

	// Checks if any of his already existing notes have the same name as the current one
	bool noteWithSameNameAlreadyExists = false;
	for (auto t : dbm.selectedInfo)
	{
		if (t == std::string(newNoteTitle.begin(), newNoteTitle.end()))
		{
			noteWithSameNameAlreadyExists = true;
		}
	}

	// If no password was given
	if (newNotePassword == L"")
	{
		// TODO: Error handling
		return;
	}

	// Insert the new note if the is no already existing note with the same name
	if (noteWithSameNameAlreadyExists != true)
	{
		// Create/Open table
		dbm.createTable("CREATE TABLE IF NOT EXISTS NOTES("
			"PARENTID       TEXT          NOT NULL, "
			"TITLE          TEXT		  NOT NULL, "
			"USERNAME       TEXT          NOT NULL, "
			"EMAIL          TEXT		  NOT NULL, "
			"PASSWORD       TEXT		  NOT NULL, "
			"DESCRIPTION    TEXT          NOT NULL); "
		); 

		   // Insert into db
		dbm.insertIntoTable("INSERT INTO NOTES (PARENTID, TITLE, USERNAME, EMAIL, PASSWORD, DESCRIPTION) "
			"VALUES"
			"("
			"'" + user.UserID + "', "  
			"'" + std::string(newNoteTitle.begin(), newNoteTitle.end()) + "', "
			"'" + std::string(newNoteUsername.begin(), newNoteUsername.end()) + "', "
			"'" + std::string(newNoteEmail.begin(), newNoteEmail.end()) + "', "
			"'" + std::string(newNotePassword.begin(), newNotePassword.end()) + "', "
			"'" + std::string(newNoteDescription.begin(), newNoteDescription.end()) + "'"
			" );");
	}
	else
	{
		//TODO: Notename already exists error handling
		;
	}
}

std::vector<std::wstring> Menu::getMenuEntries()
{
	DatabaseManager dbm;
	dbm.createTable("CREATE TABLE IF NOT EXISTS NOTES("
		"PARENTID       TEXT          NOT NULL, "
		"TITLE          TEXT		  NOT NULL, "
		"USERNAME       TEXT          NOT NULL, "
		"EMAIL          TEXT		  NOT NULL, "
		"PASSWORD       TEXT		  NOT NULL, "
		"DESCRIPTION    TEXT          NOT NULL); "
	);

	std::vector<std::wstring> data;

	dbm.selectFromTable("SELECT TITLE FROM NOTES WHERE USER_ID = " + user.UserID + " ;");

	for (std::string s : dbm.selectedInfo) {
		std::wstring temp(s.begin(), s.end());
		data.push_back(temp);
	}
	return data;
}