#pragma once

#include "../View/UI_EditNote.h"

#include "../Model/DatabaseManager.h"

#include <string>



class Edit
{
public:
	std::wstring editedTitle;
	std::wstring editedUsername;
	std::wstring editedEmail;
	std::wstring editedPassword;
	std::wstring editedDescription;

	void applyChanges(Note& base);
};