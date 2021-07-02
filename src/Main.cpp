#include "Model/FtxuiIncludes.h"
#include "View/UI_Start.h"
#include "Model/DatabaseManager.h"


int main()
{
	DatabaseManager dbm;
	std::filesystem::create_directories("./DontDelete/");
	dbm.initDB("./DontDelete/Passwords.db");

	// Starts the startwindow which lets the user login or register
	showStartWindow();
	
	return 0;
}