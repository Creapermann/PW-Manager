#include "UI_AddNote.h"
#include "../ViewModel/Menu.h"


extern ftxui::ScreenInteractive screen;

void showAddNoteWindow()
{	
	Menu menu;

	auto titleInput = ftxui::Input(&menu.newNoteTitle, "Title");
	auto usernameInput = ftxui::Input(&menu.newNoteUsername,"Username");
	auto emailInput = ftxui::Input(&menu.newNoteEmail, "Email");
	auto passwordInput = ftxui::Input(&menu.newNotePassword, "Password");
	auto descriptionInput = ftxui::Input(&menu.newNoteDescription, "Description");

	auto addButton = ftxui::Button("Add New Note", [&] {menu.createNewNote(); showMenuWindow(); }, true);
	auto quitButton = ftxui::Button("Cancel", showMenuWindow,true);

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
					) | ftxui::border | ftxui::color(ftxui::Color::White)

				) | ftxui::border | ftxui::color(ftxui::Color::GrayDark) | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 15),
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
