#include "Login.h"

#include "../View/UI_Menu.h"

#include "../Model/DatabaseManager.h"
#include "Menu.h"
#include "Model/User.h"
#include "../Shared.h"


extern User user;


void Login::loginButtonClick()
{
	if (email.size() > 4 && password.size() >= 6)
	{
		DatabaseManager dbm;

		 //Check if user exists and get the password of the user
		if(dbm.selectFromTable("SELECT PASSWORD from USERS WHERE EMAIL='"+ std::string(email.begin(), email.end()) +"'"))
		{
			 //Check if the user's password is the same as the one inputed
			if (DatabaseManager::selectedInfo[0] == std::string(password.begin(), password.end()))
			{
				DatabaseManager::selectedInfo.clear();
				// Set the global UserID
				dbm.selectFromTable("SELECT ID from USERS WHERE EMAIL='" + std::string(email.begin(), email.end()) + "'");
				user.UserID = dbm.selectedInfo[0];

				DatabaseManager::selectedInfo.clear();   //clears selectedInfo again

				Menu menu;

				menu.getMenuEntries();
				showMenuWindow();
				
			}
		}
		DatabaseManager::selectedInfo.clear();   //clears selectedInfo again
	}
}



void Login::menuButtonClick() { showStartWindow(); }
