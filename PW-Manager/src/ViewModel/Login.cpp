#include "Login.h"

#include "../View/UI_Menu.h"

#include "../Model/DatabaseManager.h"
#include "Menu.h"
#include "../Model/User.h"
#include "../Shared.h"



/// <summary>
/// Trys to login the user based on the provided data
/// </summary>
void Login::loginButtonClick()
{
	// Early enter
	/*Menu menu;
	menu.getUserNotes();
	showMenuWindow();*/

	//return;

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

				DatabaseManager::selectedInfo.clear();


				Menu menu;
				menu.getUserNotes();
				showMenuWindow();
				
			}
			else
			{
				DatabaseManager::selectedInfo.clear();
				//TODO: Password wrong error handling
			}
		}
		else
		{
			DatabaseManager::selectedInfo.clear();
			//TODO: Email wrong error handling
		}
	}
}


/// <summary>
/// Menu button clikc event
/// </summary>
void Login::menuButtonClick() { showStartWindow(); }
