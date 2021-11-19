#include "UI_ConfirmDelete.h"
#include "UI_Menu.h"

#include "DatabaseManager.h"
#include "Shared.h"

void deleteNote(Note& note)
{
	DatabaseManager dbm;

	std::string query = "DELETE FROM NOTES WHERE PARENTID = '" + user.UserID + "' AND TITLE = '" + std::string(note.title.begin(), note.title.end()) + "'";

	dbm.deleteFromTable(query);

	showMenuWindow();
}


void showConfirmDeleteWindow(Note& note)
{
	// Components
	ftxui::ButtonOption cancelButtonOption;
	cancelButtonOption.border = true;
	auto cancelButton = ftxui::Button("Cancel", showMenuWindow, cancelButtonOption);

	ftxui::ButtonOption confirmButtonOption;
	confirmButtonOption.border = true;
	auto confirmButton = ftxui::Button("Confirm", [&]() { deleteNote(note); }, confirmButtonOption);


	// Container
	auto container = ftxui::Container::Vertical
	({
		cancelButton,
		confirmButton
	});

	auto renderer = ftxui::Renderer(container, [&]()
		{
			return ftxui::vbox
			(
				ftxui::hbox
				(
					ftxui::text("Confirm Delete") | ftxui::color(ftxui::Color::Green)
				) | ftxui::border | ftxui::hcenter,

				ftxui::text(L" "),


				ftxui::vbox
				(
					ftxui::text(L" "),
					ftxui::text(L"Are you sure you want to delete this note?") | ftxui::hcenter | ftxui::color(ftxui::Color::Red) | ftxui::bold,
					ftxui::text(L" "),
					ftxui::text(L" "),
					ftxui::text(L"Deleting this note will lead to all this data beeing permanently lost!") | ftxui::color(ftxui::Color::White) | ftxui::hcenter,
					ftxui::text(L"Press Confirm to delete the note") | ftxui::color(ftxui::Color::White) | ftxui::hcenter,

					ftxui::text(L" "),
					ftxui::text(L" "),

					ftxui::hbox
					(
						cancelButton->Render() | ftxui::color(ftxui::Color::White),
						ftxui::text(L"  "),
						confirmButton->Render() | ftxui::color(ftxui::Color::Red)
					) | ftxui::hcenter
				) | ftxui::border | ftxui::color(ftxui::Color::GrayDark)


			);
		});

	screen.Loop(renderer);
}