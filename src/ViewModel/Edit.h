#pragma once

#include "UI_EditNote.h"
#include "DatabaseManager.h"

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