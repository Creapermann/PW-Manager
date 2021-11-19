#include "FtxuiIncludes.h"
#include "DatabaseManager.h"

#include "UI_Start.h"

#include "sqlite3.h"
#include "Shared.h"


int main()
{
	DatabaseManager dbm;
	std::filesystem::create_directories(dbm.folderName);
	dbm.initDB(dbm.path);

	// Shows the startwindow which lets the user login or register
	showStartWindow();

	return 0;
}