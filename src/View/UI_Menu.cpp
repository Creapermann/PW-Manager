#include "UI_Menu.h"



extern ftxui::ScreenInteractive screen;


void showMenuWindow()
{
	// Components



	// Container
	auto container = ftxui::Container::Vertical(
		{

		});


	auto renderer = ftxui::Renderer(container, [&]
		{
			return
				ftxui::hbox
				(
					ftxui::vbox
					(
						// Title
						ftxui::text(L"--- MY VAULT ---") | ftxui::hcenter,

						// Separator
						ftxui::separator()

					) | ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 70),

					ftxui::vbox
					(
						
					)
				);
		});


	screen.Loop(renderer);
}