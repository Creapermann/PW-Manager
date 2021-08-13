#include "UI_AddNote.h"
#include "../ViewModel/Menu.h"


#include <string>

extern ftxui::ScreenInteractive screen;

void showAddNoteWindow()
{	
	Menu menu;

	std::wstring e_first;

	auto titleInput = ftxui::Input(&menu.newNoteTitle, "Title");
	auto usernameInput = ftxui::Input(&menu.newNoteUsername,"Username");
	auto emailInput = ftxui::Input(&menu.newNoteEmail, "Email");
	auto passwordInput = ftxui::Input(&menu.newNotePassword, "Password");
	auto descriptionInput = ftxui::Input(&menu.newNoteDescription, "Description");

	ftxui::ButtonOption addButtonOption;
	addButtonOption.border = true;
	auto addButton = ftxui::Button("Add New Note", [&] { menu.createNewNote(e_first); }, addButtonOption);
	
	ftxui::ButtonOption quitButtonOption;
	quitButtonOption.border = true;
	auto quitButton = ftxui::Button("Cancel", showMenuWindow, quitButtonOption);

	auto container = ftxui::Container::Vertical({
		titleInput,
		usernameInput,
		emailInput,
		passwordInput,
		descriptionInput,
		addButton,
		quitButton,
	});

	auto renderer = ftxui::Renderer(container, [&] {
		return
			ftxui::vbox(
				ftxui::hbox(
					ftxui::text(L"Add a new note") | ftxui::flex | ftxui::hcenter | ftxui::color(ftxui::Color::Green)

				) | ftxui::border | ftxui::hcenter,

				// Form
				ftxui::vbox
				(
					ftxui::hbox(
						ftxui::text(L"Title*:       "),
						titleInput->Render()
					) | ftxui::border | ftxui::color(ftxui::Color::White),

					ftxui::hbox(
						ftxui::text(L"Username:     "),
						usernameInput->Render()
					) | ftxui::border | ftxui::color(ftxui::Color::White),


					ftxui::hbox
					(
						ftxui::text(L"Email:        "),
						emailInput->Render()
					) | ftxui::border | ftxui::color(ftxui::Color::White),

					ftxui::hbox
					(
						ftxui::text(L"Password*:    "),
						passwordInput->Render()
					) | ftxui::border | ftxui::color(ftxui::Color::White),

					ftxui::hbox(
						ftxui::text(L"Description:  "),  
						descriptionInput->Render()
					) | ftxui::border | ftxui::color(ftxui::Color::White),

					ftxui::text(L""),
					ftxui::text(L" " + e_first) | ftxui::color(ftxui::Color::Red)

				) | ftxui::border | ftxui::color(ftxui::Color::GrayDark) | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 15),

				ftxui::text(L""),

				ftxui::vbox(
					ftxui::hbox(
						addButton->Render()
					)|ftxui::hcenter,
					ftxui::hbox(
						quitButton->Render()
					)|ftxui::hcenter
				)
			);
		});

	screen.Loop(renderer);
}
