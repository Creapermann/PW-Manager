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

public:
	void generatePassword();
	void copyPasswordToClipboard();
};