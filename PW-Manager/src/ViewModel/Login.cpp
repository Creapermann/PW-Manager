#include "Login.h"

#include "../View/UI_Menu.h"

#include "../Model/DatabaseManager.h"
#include "Menu.h"
#include "../Model/User.h"
#include "../Shared.h"



/// <summary>
/// Trys to login the user based on the provided data
/// </summary>
void Login::loginButtonClick(std::wstring& e_first)
{
	// Early enter
	/*Menu menu;
	menu.getUserNotes();
	showMenuWindow();*/

	//return;

	if (email.size() > 0 && password.size() > 0)
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
				
				e_first = L"The provied password is wrong!";
				return;
			}
		}
		else
		{
			DatabaseManager::selectedInfo.clear();
			
			e_first = L"The provied email is wrong!";
			return;
		}
	}
}


/// <summary>
/// Menu button clikc event
/// </summary>
void Login::menuButtonClick() { showStartWindow(); }
