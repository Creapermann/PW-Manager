#include "UI_Register.h"
#include "../Model/ProgramInfo.h"

void showRegisterWindow() //i 
{
	auto screen = ftxui::ScreenInteractive::Fullscreen();
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
