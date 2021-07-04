#include "UI_Settings.h"
#include "../Shared.h"



void showSettingsWindow()
{
	// Components
	


	// Container
	auto container = ftxui::Container::Vertical
	({
			
	});


	auto renderer = ftxui::Renderer(container, [&]
	{
		return
			ftxui::vbox
			(
				ftxui::text(L"a")
			);
	});

	screen.Loop(renderer);
}