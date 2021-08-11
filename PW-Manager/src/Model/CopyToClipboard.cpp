#include "CopyToClipboard.h"


void copyToClipboard(const std::string& text)
{
	// Copies the current password to the clipboard
	clip::set_text(std::string(text));	
}