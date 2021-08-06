#include "UI_Credits.h"
#include "UI_Start.h"
#include "../Model/ProgramInfo.h"

#include "../Shared.h"


void showCreditsWindow()
{
	// Components
	int dev1RightSize = 28;
	auto dev1name = ftxui::Renderer([&] { return ftxui::text(L"        David Lazarescu"); });
	auto dev1email = ftxui::Renderer([&] { return ftxui::text(L"     davidlazarescusc@gmail.com"); });
	auto dev1Split = ftxui::ResizableSplitLeft(dev1name, dev1email, &dev1RightSize);

	auto menuButton = ftxui::Button("<< Back to menu", showStartWindow, true);


	// Container
	auto container = ftxui::Container::Vertical(
		{
			menuButton
		});

	auto renderer = ftxui::Renderer(container, [&]
		{
			return
				ftxui::vbox
				(
					// Header
					ftxui::hbox
					(
						// Title
						ftxui::text(std::wstring(pInfo::name.begin(), pInfo::name.end())) | ftxui::flex_grow
						| ftxui::color(ftxui::Color::Green),

						// Version
						ftxui::text(L"v_" + std::wstring(pInfo::version.begin(), pInfo::version.end()))

					) | ftxui::border,

					//Spacing
					ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 2),
					

					// Developers
					ftxui::vbox
					(
						ftxui::window
						(
							ftxui::hbox
							(
								ftxui::text(L"Developer:") | ftxui::color(ftxui::Color::White)  | ftxui::hcenter | ftxui::bold
							),

							ftxui::vbox
							(

								// Spacing
								ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 1),

								// Developer 1
								ftxui::hbox
								(
									dev1Split->Render() | ftxui::center

								) | ftxui::border | ftxui::color(ftxui::Color::White),



								// Spacing
								ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 1)

							)
						)
					) | ftxui::color(ftxui::Color::GrayDark),


					// Spacing
					ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 4),


					// Program information
					ftxui::vbox
					(
						ftxui::window
						(
							ftxui::text(L"Program-Info:") | ftxui::color(ftxui::Color::White)  | ftxui::hcenter,  // Window title
							(
								// Window content
								ftxui::vbox
								(
									// Spacing
									ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 1),

									ftxui::text(L"Name:            " + std::wstring(pInfo::name.begin(), pInfo::name.end())) | ftxui::color(ftxui::Color::White),
									ftxui::text(L"Current version: " + std::wstring(pInfo::version.begin(), pInfo::version.end())) | ftxui::color(ftxui::Color::White),
									ftxui::text(L"Website:         " + std::wstring(pInfo::website.begin(), pInfo::website.end())) | ftxui::color(ftxui::Color::White),
									
									// Spacing
									ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 1)
								)
							)
						)
					) | ftxui::color(ftxui::Color::GrayDark),


					// Spacing
					ftxui::hbox() | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 1),

					// Menu button
					menuButton->Render() | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 8)
				);
		});

	screen.Loop(renderer);
}