#include "Menu.h"

#include "../Model/DatabaseManager.h"
#include "../Model/User.h"

#include <Windows.h>
#include <conio.h>


extern User user;


void Menu::generatePassword()
{
	generatedPassword = L"63!@Rh}mG74Rv>BK";
}

void Menu::copyPasswordToClipboard()
{
	OpenClipboard(0);
	EmptyClipboard();
	const char* op = "Hello this is a test";
	const size_t ln = strlen(op) + 1;
	HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, ln);
	memcpy(GlobalLock(h), op, ln);
	GlobalUnlock(h);
	SetClipboardData(CF_TEXT, h);
	CloseClipboard();
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
