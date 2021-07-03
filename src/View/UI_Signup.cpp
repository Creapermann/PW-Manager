#include "UI_Signup.h"
#include "../ViewModel/Signup.h"

#include "../Shared.h"



void showSignupWindow()
{
	Signup signup;

	// Components
	auto menuButton = ftxui::Button(" <<  Back to menu", showStartWindow, true);
	auto signupButton = ftxui::Button("Signup", [&] {signup.signupButtonClick(signup.firstname, signup.lastname, signup.email, signup.password, signup.confirmPassword);}, true);

	ftxui::Component firstnameInput = ftxui::Input(&signup.firstname, "First name");
	ftxui::Component lastnameInput = ftxui::Input(&signup.lastname, "Last name");
	ftxui::Component emailInput = ftxui::Input(&signup.email, "someone@example.com");
	ftxui::Component passwordInput = ftxui::Input(&signup.password, "********");
	ftxui::Component confirmPasswordInput = ftxui::Input(&signup.confirmPassword, "********");

	// Container
	auto container = ftxui::Container::Vertical(
		{
			firstnameInput,
			lastnameInput,
			emailInput,
			passwordInput,
			confirmPasswordInput,
			signupButton,
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
							ftxui::text(L"Signup") | ftxui::flex | ftxui::center | ftxui::color(ftxui::Color::Green)
						) | ftxui::border

					),

					// Signup form
					ftxui::vbox
					(
						ftxui::hbox
						(
							ftxui::text(L"First name:        "),
							firstnameInput->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White) | ftxui::flex,

						ftxui::hbox
						(
							ftxui::text(L"Last name:         "),
							lastnameInput->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),
						ftxui::hbox
						(
							ftxui::text(L"Email:             "),
							emailInput->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::text(L"Password:          "),
							passwordInput->Render() /*| ftxui::color(ftxui::Color::Black) */
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::text(L"Confirm Password:  "),
							confirmPasswordInput->Render() /* | ftxui::color(ftxui::Color::Black)*/
						) | ftxui::border | ftxui::color(ftxui::Color::White),
						ftxui::hbox(
							signupButton->Render()
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
