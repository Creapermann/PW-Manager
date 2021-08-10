#include "Model/FtxuiIncludes.h"
#include "Model/DatabaseManager.h"

#include "View/UI_Start.h"

#include <sqlite3.h>


int main()
{
	DatabaseManager dbm;
	std::filesystem::create_directories(dbm.folderName);
	dbm.initDB(dbm.path);

	std::wstring a;
	ftxui::Input(&a, L"a");

	// Shows the startwindow which lets the user login or register
	showStartWindow();

	return 0;
}