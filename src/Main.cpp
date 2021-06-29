#include "FtxuiIncludes.h"
#include "StartWindow.h"


int main()
{

	if (__cplusplus == 201703L) 
		std::cout << "C++17\n";
	else if (__cplusplus == 201402L) 
		std::cout << "C++14\n";
	else if (__cplusplus == 201103L) 
		std::cout << "C++11\n";
	else if (__cplusplus == 199711L) 
		std::cout << "C++98\n";
	else
		std::cout << "pre-standard C++\n";

	// Starts the startwindow which lets the user login or register
	//auto screen = ftxui::ScreenInteractive::Fullscreen(); 
	//Do u still wanna try?
	// ok as you see and wan
	showStartWindow(ftxui::ScreenInteractive::Fullscreen());

	

	return 0;
}