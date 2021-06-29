#include "UI_Login.h"
#include "../ViewModel/Login.h"




void showLoginWindow()
{
	// Screen
	auto screen = ftxui::ScreenInteractive::Fullscreen();


	// Components
	auto menuButton = ftxui::Button("<< Back to menu", showStartWindow, false);
	auto loginButton = ftxui::Button("Login", showStartWindow, true);

	ftxui::Component emailInputBox = ftxui::Input(&email, "someone@example.com");
	ftxui::Component passwordInputBox = ftxui::Input(&password, "********");


	// Container
	auto container = ftxui::Container::Vertical(
		{
			emailInputBox,
			passwordInputBox,
			loginButton,
			menuButton,

		});


	auto renderer = ftxui::Renderer(container, [&]
		{
			return
				ftxui::vbox(
					ftxui::vbox
					(
						// Title
						ftxui::hbox
						(
							ftxui::text(L"Master Login") | ftxui::flex | ftxui::center | ftxui::color(ftxui::Color::Green)
						) | ftxui::border

					),

					// Login form
					ftxui::vbox
					(

						ftxui::hbox
						(
							ftxui::text(L"Email:     "),
							emailInputBox->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::text(L"Password:  "),
							passwordInputBox->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),
						ftxui::hbox(
							loginButton->Render()
						) | ftxui::center | ftxui::color(ftxui::Color::White)

					) | ftxui::border | ftxui::color(ftxui::Color::GrayDark),

					// Menu button
					ftxui::vbox
					(
						ftxui::hbox
						(
							menuButton->Render()
						)
					) | ftxui::yflex
				);
		});
	screen.Loop(renderer);
}
