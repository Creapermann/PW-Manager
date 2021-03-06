#include "UI_Login.h"
#include "Login.h"
#include "Shared.h"


#include <string>



void showLoginWindow()
{
	Login login;


	// Error-Handling
	std::wstring e_first;

	// Components
	ftxui::ButtonOption menuButtonOption;
	menuButtonOption.border = true;
	auto menuButton = ftxui::Button(" <<  Back  ", showStartWindow, menuButtonOption);

	ftxui::ButtonOption loginButtonOption;
	loginButtonOption.border = true;
	auto loginButton = ftxui::Button("Login", [&] {login.loginButtonClick(e_first); }, loginButtonOption);


	ftxui::Component emailInput = ftxui::Input(&login.email, "someone@example.com");
	
	ftxui::InputOption passwordInputOption;
	passwordInputOption.password = true;
	ftxui::Component passwordInput = ftxui::Input(&login.password, "********", passwordInputOption);


	// Container
	auto container = ftxui::Container::Vertical(
		{
			emailInput,
			passwordInput,
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
							ftxui::text(L"Login") | ftxui::flex | ftxui::center | ftxui::color(ftxui::Color::Green)
						) | ftxui::border

					) | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 4),

					// Login form
					ftxui::vbox
					(

						ftxui::hbox
						(
							ftxui::text(L"Email:     "),
							emailInput->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::text(L"Password:  "),
							passwordInput->Render() /* | ftxui::bgcolor(ftxui::Color::White) */
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::text(L" " + e_first) | ftxui::color(ftxui::Color::Red),

						ftxui::hbox(
							loginButton->Render()
						) | ftxui::center | ftxui::color(ftxui::Color::White)

					) | ftxui::border | ftxui::color(ftxui::Color::GrayDark) | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 15),

					// Menu button
					ftxui::vbox
					(
						ftxui::hbox
						(
							menuButton->Render()
						)
					)
				);
		});
	screen.Loop(renderer);
}
