#include "PW-Manager.h"
#include "ProgramInfo.h"


int main(void)
{
	auto screen = ftxui::ScreenInteractive::Fullscreen();

	// Define the menu
	std::vector<std::wstring> entries = {
		L"Login",
		L"Create New Account",
		L"Exit",
	};

	int selected = 0;
	auto menu = ftxui::Menu(&entries, &selected);

	// ftxui::MenuBase::From(menu)->selected_style = ftxui::bold;
	ftxui::MenuBase::From(menu)->focused_style = ftxui::bgcolor(ftxui::Color::Blue);

	ftxui::MenuBase::From(menu)->on_enter = screen.ExitLoopClosure();

	int x = 0;
	ftxui::Component container = ftxui::Container::Vertical({ menu }, &x);

	auto renderer = ftxui::Renderer(container, [&] 
	{
			return
				ftxui::vbox
				({
					ftxui::hbox
					({
						//Title
						ftxui::text(std::wstring(pInfo::name.begin(), pInfo::name.end())) | ftxui::flex | ftxui::bold | ftxui::color(ftxui::Color::Green),
						ftxui::text(std::wstring(pInfo::version.begin(), pInfo::version.end())),
						// Separator
					}) | ftxui::border,

					//Seperator
					ftxui::separator(),

					ftxui::vbox({
						//Menu
						menu->Render()
					}) | ftxui::border,
			});
	});
	screen.Loop(renderer);

	std::cout << "Selected option = " << selected << std::endl;
	return 0;
}
