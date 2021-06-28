#include "LoginWindow.h"



void showLoginWindow(ftxui::ScreenInteractive screen)
{
	auto renderer = ftxui::Renderer([&]
		{
			return
				ftxui::vbox
				(
					ftxui::hbox
					(
						ftxui::text(L"This is the register window")
					)
				);
		});
	screen.Loop(renderer);
}