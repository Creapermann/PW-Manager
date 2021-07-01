#include "Login.h"
#include "../View/UI_Menu.h"


void Login::loginButtonClick(std::wstring email, std::wstring password) 
{
	showMenuWindow();
}

void Login::menuButtonClick() { showStartWindow(); }
