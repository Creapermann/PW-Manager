#pragma once

#include <string>
#include "../Model/FtxuiIncludes.h"
#include "../Model/DatabaseManager.h"

class Note
{
	std::wstring Title{ L"" };
	std::wstring Username{ L"" };
	std::wstring Email{ L"" };
	std::wstring Password{ L"" };
	std::wstring Description{ L"" };
};



class Menu
{

public:
	std::wstring generatedPasswordLength;
	bool lowercaseLetters = true;
	bool uppercaseLetters = true;
	bool includeNumbers = true;
	bool includeSymbols = true;
	std::wstring generatedPassword{L""};


	std::wstring newNoteTitle{L""};
	std::wstring newNoteUsername{L""};
	std::wstring newNoteEmail{L""};
	std::wstring newNotePassword{L""};
	std::wstring newNoteDescription{L""};

	std::vector<std::wstring> notes;
	

public:
	void generatePassword();
	void copyPasswordToClipboard();
	
	void createNewNote();
	void getMenuEntries();
};