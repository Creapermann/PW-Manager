#include "Login.h"
#include "../View/UI_Menu.h"


void Login::loginButtonClick(std::wstring email, std::wstring password)
{
	if (email.size() > 4 && password.size() > 6)
	{
		showMenuWindow();
	}
}

void Login::menuButtonClick() { showStartWindow(); }
