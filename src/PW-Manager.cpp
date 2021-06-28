#include "PW-Manager.h"
#include "ProgramInfo.h"


void test()
{
	std::cout << "a\n";
}


int main(void)
{
	// The screen
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

	std::cout << "Selected option = " << selected << std::endl;
	return 0;
}
