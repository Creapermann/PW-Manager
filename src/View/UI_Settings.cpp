#include "UI_Settings.h"
#include "UI_Start.h"
#include "UI_Menu.h"

#include "../Model/ProgramInfo.h"

#include "../Shared.h"



void showSettingsWindow()
{
	// Components
	auto logOutButton = ftxui::Button("Logout", showStartWindow, false);
	auto menuButton = ftxui::Button("Back", showMenuWindow, false);


	// Container
	auto container = ftxui::Container::Vertical
	({
		menuButton,
		logOutButton
	});


	auto renderer = ftxui::Renderer(container, [&]
	{
			return
				ftxui::vbox
				(
					ftxui::hbox
					(
						// Title
						ftxui::text(std::wstring(pInfo::name.begin(), pInfo::name.end())) |
						ftxui::flex | ftxui::bold | ftxui::color(ftxui::Color::Green) | ftxui::center,

						// Version
						ftxui::text(L"v_" + std::wstring(pInfo::version.begin(), pInfo::version.end()))

					) | ftxui::border,

					// Separator
					ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),

					ftxui::vbox
					(
						ftxui::vbox
						(
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon")
						),

						ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),

						ftxui::vbox
						(
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon")
						),

						ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),

						ftxui::vbox
						(
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon"),
							ftxui::text(L"coming soon")
						)
					) | ftxui::border,

					ftxui::text(L""),

					ftxui::hbox
					(
						menuButton->Render(),
						ftxui::text(L"   "),
						logOutButton->Render()
					)
			);
	});

	screen.Loop(renderer);
}