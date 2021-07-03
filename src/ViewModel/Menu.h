#include <string>



class Menu
{

public:
	std::wstring generatedPasswordLength;
	bool lowercaseLetters = true;
	bool uppercaseLetters = true;
	bool includeNumbers = true;
	bool includeSymbols = true;

	std::wstring generatedPassword{L"63!@Rh}mG74Rv>BK"};
};