#pragma once

#include <string>



class Note
{
public:
	std::wstring parentID;
	std::wstring title;
	std::wstring username;
	std::wstring email;
	std::wstring password;
	std::wstring description;

	bool operator==(const Note& note) const
	{
		return parentID == note.parentID && title == note.title && username == note.username && email == note.email
			&& password == note.password && description == note.description;
	}

private:

};