#include "UI_Start.h"
#include "UI_Register.h"
#include "UI_Login.h"
#include "../Model/ProgramInfo.h"


void showStartWindow()
{

	auto screen = ftxui::ScreenInteractive::Fullscreen();

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




	ftxui::Component container = ftxui::Container::Vertical({ menu });
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
	switch (selected)
	{
	case 0:
		showLoginWindow();
		break;
	case 1:
		showRegisterWindow();
		break;
	case 2:
		std::cout << "Exit\n";
		break;
	}
}
