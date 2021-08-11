#include "Edit.h"

#include "../Shared.h"

#include <string>


void Edit::applyChanges(Note& base)
{
	DatabaseManager dbm;

	if (base.title != editedTitle)
	{
		std::string query = "UPDATE NOTES SET TITLE = '" + std::string(editedTitle.begin(), editedTitle.end()) + 
			"' WHERE TITLE = '" + std::string(base.title.begin(), base.title.end()) + "' AND PARENTID = '" + user.UserID + "'";

		base.title = editedTitle;

		dbm.updateTable(query);
	}

	if (base.username != editedUsername)
	{
		std::string query = "UPDATE NOTES SET USERNAME = '" + std::string(editedUsername.begin(), editedUsername.end()) +
			"' WHERE TITLE = '" + std::string(base.title.begin(), base.title.end()) + "' AND PARENTID = '" + user.UserID + "'";

		base.username = editedUsername;

		dbm.updateTable(query);
	}

	if (base.email != editedEmail)
	{
		std::string query = "UPDATE NOTES SET EMAIL = '" + std::string(editedEmail.begin(), editedEmail.end()) +
			"' WHERE TITLE = '" + std::string(base.title.begin(), base.title.end()) + "' AND PARENTID = '" + user.UserID + "'";

		base.email = editedEmail;

		dbm.updateTable(query);
	}

	if (base.password != editedPassword)
	{
		std::string query = "UPDATE NOTES SET PASSWORD = '" + std::string(editedPassword.begin(), editedPassword.end()) +
			"' WHERE TITLE = '" + std::string(base.title.begin(), base.title.end()) + "' AND PARENTID = '" + user.UserID + "'";

		base.password = editedPassword;

		dbm.updateTable(query);
	}

	if (base.description != editedDescription)
	{
		std::string query = "UPDATE NOTES SET DESCRIPTION = '" + std::string(editedDescription.begin(), editedDescription.end()) +
			"' WHERE TITLE = '" + std::string(base.title.begin(), base.title.end()) + "' AND PARENTID = '" + user.UserID + "'";

		base.description = editedDescription;

		dbm.updateTable(query);
	}
}
