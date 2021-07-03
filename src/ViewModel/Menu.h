#include <string>



class Menu
{

public:
	std::wstring generatedPasswordLength;
	bool lowercaseLetters = true;
	bool uppercaseLetters = true;
	bool includeNumbers = true;
	bool includeSymbols = true;
	std::wstring generatedPassword{L""};


	std::wstring newNoteTitle{L"Youtube"};
	std::wstring newNoteUsername{L"Creapermann"};
	std::wstring newNoteEmail{L"creapermann37@gmail.com"};
	std::wstring newNotePassword{L"123456"};
	std::wstring newNoteDescription{L"My youtube login data which is safely stored by this awsome password manager"};
	

public:
	void generatePassword();
	void copyPasswordToClipboard();
	
	void createNewNote();
};