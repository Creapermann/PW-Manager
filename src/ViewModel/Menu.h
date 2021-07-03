#pragma once

#include <string>
#include "../Model/FtxuiIncludes.h"
#include "../Model/DatabaseManager.h"


class Menu
{

public:
	std::wstring generatedPasswordLength;
	bool lowercaseLetters = true;
	bool uppercaseLetters = true;
	bool includeNumbers = true;
	bool includeSymbols = true;
	std::wstring generatedPassword{L""};


	std::wstring newNoteTitle{L"Google"};
	std::wstring newNoteUsername{L"Creapermann"};
	std::wstring newNoteEmail{L"creapermann37@gmail.com"};
	std::wstring newNotePassword{L"1234567"};
	std::wstring newNoteDescription{L"My google login data which is safely stored by this awsome password manager"};
	

public:
	void generatePassword();
	void copyPasswordToClipboard();
	
	void createNewNote();
	std::vector<std::wstring> getMenuEntries();
};