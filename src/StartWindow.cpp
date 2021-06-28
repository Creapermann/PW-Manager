#include "StartWindow.h"
#include "RegisterWindow.h"
#include "LoginWindow.h"
#include "ProgramInfo.h"



void showStartWindow(ftxui::ScreenInteractive screen)
{

#pragma region Components

	/*Menu*/
	// Menu items
	std::vector<std::wstring> entries = {
		L"Login",
		L"Create New Account",
		L"Exit",
	};
	// Selected item
	int selected = 0;
	// Menu
	auto menu = ftxui::Menu(&entries, &selected);
	// Addaptions
	ftxui::MenuBase::From(menu)->on_enter = screen.ExitLoopClosure();
	ftxui::MenuBase::From(menu)->focused_style = ftxui::bgcolor(ftxui::Color::Blue);

#pragma endregion




	int x = 0;
	ftxui::Component container = ftxui::Container::Vertical({ menu }, &x);
	auto renderer = ftxui::Renderer(container, [&]
		{
			return
				ftxui::vbox
				(
					ftxui::hbox
					(
						// Title
						ftxui::text(std::wstring(pInfo::name.begin(), pInfo::name.end())) | ftxui::flex | ftxui::bold | ftxui::color(ftxui::Color::Green),

						// Version
						ftxui::text(L"v_" + std::wstring(pInfo::version.begin(), pInfo::version.end()))

					) | ftxui::border,

					// Seperator
					ftxui::separator(),

					ftxui::vbox(
						// Menu
						menu->Render()
					) | ftxui::border
				);
		});
	screen.Loop(renderer);



	//Validate the users input
	switch(selected)
	{
		case 0:
			//showLoginWindow(screen);
			break;
		case 1:
			//showRegisterWindow(screen);
			break;
		case 2:
			std::cout << "Exit\n";
			break;
	}
}
