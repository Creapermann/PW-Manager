#include "CopyToClipboard.h"


#include <string>


void copyToClipboard(const std::string& text)
{
	// Copies the current password to the clipboard
	clip::set_text(text);
}

std::string getFromClipboard()
{
	std::string temp;

	return temp;
}