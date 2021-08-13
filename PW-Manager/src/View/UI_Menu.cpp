#include "UI_Menu.h"

#include "UI_AddNote.h"
#include "UI_MenuSettings.h"
#include "UI_EditNote.h"

#include "../Model/CopyToClipboard.h"

#include "../Shared.h"



void showMenuWindow()
{
	Menu menu;

	std::wstring e_first;

	
	int size{ 60 };

	// Components
	std::wstring searchStr;
	ftxui::InputOption searchInputOption;
	searchInputOption.on_change = [&]() { ; };
	auto searchInput = ftxui::Input(&searchStr, L"...", searchInputOption);


	ftxui::ButtonOption settingsButtonOption;
	settingsButtonOption.border = false;
	auto settingsButton = ftxui::Button("(settings)", showMenuSettingsWindow, settingsButtonOption);

	ftxui::ButtonOption newNoteButtonOption;
	newNoteButtonOption.border = true;
	auto newNoteButton = ftxui::Button("Add new note", showAddNoteWindow, newNoteButtonOption);

	ftxui::ButtonOption generatePwButtonOption;
	generatePwButtonOption.border = false;
	auto generatePasswordButton = ftxui::Button(L"Generate", [&] { menu.generatePassword(e_first); }, generatePwButtonOption);

	ftxui::ButtonOption copyPwButtonOption;
	copyPwButtonOption.border = false;
	auto copyPasswordButton = ftxui::Button("Copy To Clipboard", [&] { copyToClipboard(std::string(menu.generatedPassword.begin(), 
		menu.generatedPassword.end())); }, copyPwButtonOption);


	ftxui::Component passwordLengthInput = ftxui::Input(&menu.generatedPasswordLength, L"0");


	auto lowercaseCheckBox = ftxui::Checkbox(L"include lowercase (e.g. abcd)", &menu.lowercaseLetters);
	auto uppercaseCheckBox = ftxui::Checkbox(L"include uppercase (e.g. ABCD)", &menu.uppercaseLetters);
	auto numbersCheckBox = ftxui::Checkbox(L"include numbers   (e.g. 1234)", &menu.includeNumbers);
	auto symbolsCheckBox = ftxui::Checkbox(L"include symbols   (e.g. @#$%)", &menu.includeSymbols);


	// Contains the currently owned notes of the user
	int selected = 0;
	std::vector<std::wstring> entries = menu.getUserNotes();

	ftxui::MenuOption vaultMenuOption;
	vaultMenuOption.on_enter = [&]() { showEditNoteWindow(menu.userNotes[selected]); };
	auto vaultMenu = ftxui::Menu(&entries, &selected, vaultMenuOption);

	// Container
	auto container = ftxui::Container::Vertical({
			newNoteButton,
			searchInput,
			vaultMenu,
			settingsButton,
			passwordLengthInput,
			lowercaseCheckBox,
			uppercaseCheckBox,
			numbersCheckBox,
			symbolsCheckBox,
			generatePasswordButton,
			copyPasswordButton
	});




	auto renderer = ftxui::Renderer(container, [&]
		{
			return
				ftxui::hbox(

					// Left side
					ftxui::vbox
					(
						ftxui::hbox
						(
							// Title
							ftxui::text(L"--- MY VAULT ---") | ftxui::center,
							newNoteButton->Render()
						),

						// Separator
						ftxui::separator(),

						ftxui::window
						(
							"A",
							searchInput->Render(),
						),

						ftxui::separator() |ftxui::color(ftxui::Color::GrayDark),

						// Notes menu
						vaultMenu->Render() | ftxui::frame | ftxui::size(ftxui::Direction::HEIGHT, ftxui::Constraint::LESS_THAN, 30)

					) | ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 65),



					// Right side
					ftxui::vbox
					(
						ftxui::hbox
						(
							ftxui::text(std::wstring(pInfo::name.begin(), pInfo::name.end())) | ftxui::flex,
							settingsButton->Render() | ftxui::align_right,
							ftxui::text(L" ") | ftxui::align_right | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 10)
						),

						// Separator
						ftxui::separator(),

						// Spacing
						ftxui::text(L" "),

						// Password Generator
						ftxui::vbox
						(
							ftxui::text(L"Password Generator") | ftxui::color(ftxui::Color::White) | ftxui::hcenter,

							ftxui::separator(),

							ftxui::vbox
							(
								ftxui::hbox
								(
									ftxui::text(L"length: "),
									passwordLengthInput->Render() | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 4)
									| ftxui::bgcolor(ftxui::Color::Black) | ftxui::color(ftxui::Color::Green)
								),

								ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),

								// Checkboxes
								lowercaseCheckBox->Render(),
								uppercaseCheckBox->Render(),
								numbersCheckBox->Render(),
								symbolsCheckBox->Render(),

								//Spacing
								ftxui::text(L" "),

								generatePasswordButton->Render() | ftxui::border | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 8),


								ftxui::text(L" " + e_first) | ftxui::color(ftxui::Color::Red),

								ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),


								ftxui::text(menu.generatedPassword) | ftxui::hcenter,


								ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),

								copyPasswordButton->Render() | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 15)

							) | ftxui::color(ftxui::Color::White)

						) | ftxui::border




					) | ftxui::border | ftxui::flex
				);
	});

	screen.Loop(renderer);
}