#include "FtxuiIncludes.h"
#include "StartWindow.h"


int main()
{
	// Starts the startwindow which lets the user login or register
	//auto screen = ftxui::ScreenInteractive::Fullscreen();

	showStartWindow(ftxui::ScreenInteractive::Fullscreen());

	

	return 0;
}