#include "Login.h"

#include "../View/UI_Menu.h"

#include "../Model/DatabaseManager.h"
#include "Model/User.h"


extern User user;


void Login::loginButtonClick(std::wstring email, std::wstring password)
{
	if (email.size() > 4 && password.size() >= 6)
	{
		DatabaseManager dbm;
		if(dbm.selectFromTable("SELECT PASSWORD from USERS WHERE EMAIL='"+ std::string(email.begin(), email.end()) +"'"))
		{
			if (DatabaseManager::selectedInfo[0] == std::string(password.begin(), password.end()))
			{
				dbm.selectFromTable("SELECT ID from USERS WHERE EMAIL='" + std::string(email.begin(), email.end()) + "'");
				user.UserID = dbm.selectedInfo[0];

				DatabaseManager::selectedInfo.clear();   //clears selectedInfo again
				showMenuWindow();
			}
		}
		DatabaseManager::selectedInfo.clear();   //clears selectedInfo again
	}
}



void Login::menuButtonClick() { showStartWindow(); }
