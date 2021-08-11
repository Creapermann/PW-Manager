#include "UI_EditNote.h"
#include "../Model/FtxuiIncludes.h"

#include "../Shared.h"

#include "../ViewModel/Edit.h"
#include "../View/UI_Menu.h"



void showEditNoteWindow(Note& note)
{
	Edit edit;

	// Set placeholders
	edit.editedTitle = note.title;
	edit.editedUsername = note.username;
	edit.editedEmail = note.email;
	edit.editedPassword = note.password;
	edit.editedDescription = note.description;

	// Components
	auto title = ftxui::Input(&edit.editedTitle, "");
	auto username = ftxui::Input(&edit.editedUsername, "");
	auto email = ftxui::Input(&edit.editedEmail, "");
	auto password = ftxui::Input(&edit.editedPassword, "");
	auto description = ftxui::Input(&edit.editedDescription, "");


	ftxui::ButtonOption copyPasswordButtonOption;
	copyPasswordButtonOption.border = false;
	auto copyPasswordButton = ftxui::Button("copy", [&]() { ; }, copyPasswordButtonOption);

	ftxui::ButtonOption saveButtonOption;
	saveButtonOption.border = true;
	auto saveButton = ftxui::Button("Save changes", [&]() { edit.applyChanges(note); showMenuWindow(); }, saveButtonOption);

	ftxui::ButtonOption cancelButtonOption;
	cancelButtonOption.border = true;
	auto cancelButton = ftxui::Button("Cancel", showMenuWindow, cancelButtonOption);


	// Container
	auto container = ftxui::Container::Vertical(
	{
		title,
		username,
		email,
		password,
		copyPasswordButton,
		description,
		
		saveButton,
		cancelButton
	});


	auto renderer = ftxui::Renderer(container, [&]
		{
			return
				ftxui::vbox
				(
					// Header
					ftxui::hbox(
						ftxui::text(L"Edit note") | ftxui::flex | ftxui::hcenter | ftxui::color(ftxui::Color::Green)

					) | ftxui::border | ftxui::hcenter,

					//Main content
					ftxui::vbox
					(

						ftxui::hbox
						(
							ftxui::text("Title:        "),
							title->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::text("Username:     "),
							username->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::text("E-Mail:       "),
							email->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::hbox
						(
							ftxui::hbox
							(
								ftxui::text("Password:     "),
								password->Render()
							) | ftxui::border | ftxui::color(ftxui::Color::White) | ftxui::xflex_grow,

							ftxui::hbox
							(
								copyPasswordButton->Render()
							) | ftxui::border | ftxui::color(ftxui::Color::White)

						),

						ftxui::hbox
						(
							ftxui::text("Description:  "),
							description->Render()
						) | ftxui::border | ftxui::color(ftxui::Color::White),

						ftxui::text(" "),
						ftxui::text(" Warning: All the changes you apply are irreversible!") | ftxui::color(ftxui::Color::Red),
						ftxui::text(" ")

					) | ftxui::border | ftxui::color(ftxui::Color::GrayDark),
					
					saveButton->Render() | ftxui::center,
					cancelButton->Render() | ftxui::center
				);
		});

	screen.Loop(renderer);
}
