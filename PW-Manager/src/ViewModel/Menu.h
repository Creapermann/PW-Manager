#pragma once

#include <string>
#include "../Model/FtxuiIncludes.h"
#include "../Model/DatabaseManager.h"
#include "../Model/Note.h"



class Menu
{

public:
	// Password generator
	std::wstring generatedPasswordLength;
	bool lowercaseLetters = true;
	bool uppercaseLetters = true;
	bool includeNumbers = true;
	bool includeSymbols = true;
	std::wstring generatedPassword{L""};

	// New notes
	std::wstring newNoteTitle{L""};
	std::wstring newNoteUsername{L""};
	std::wstring newNoteEmail{L""};
	std::wstring newNotePassword{L""};
	std::wstring newNoteDescription{L""};


public:
	std::vector<Note> userNotes;

	void generatePassword();
	void copyPasswordToClipboard();
	
	void createNewNote();
	std::vector<std::wstring> getUserNotes();
};