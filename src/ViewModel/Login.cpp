#include "Login.h"
#include "../View/UI_Menu.h"
#include "../Model/DatabaseManager.h"



void Login::loginButtonClick(std::wstring email, std::wstring password)
{
	if (email.size() > 4 && password.size() > 6)
	{
		DatabaseManager dbm;
		dbm.selectFromTable("SELECT PASSWORD from USERS WHERE EMAIL='"+ std::string(email.begin(), email.end()) +"'");
		if (DatabaseManager::selectedInfo[0] == std::string(password.begin(), password.end()))
		{
			showMenuWindow();
		}
	}
}



void Login::menuButtonClick() { showStartWindow(); }
