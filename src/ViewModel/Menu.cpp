#include "Menu.h"

//#include <conio.h>
//#include <stdio.h>
//#include <cstdlib>
//#include <Windows.h>
//#include <winuser.h>
//#include <cmath>
//#include <iostream>
//#include <iomanip>
//#include <complex>
//#include <string>


void Menu::generatePassword()
{
	generatedPassword = L"63!@Rh}mG74Rv>BK";
}

void Menu::copyPasswordToClipboard()
{
	/*HWND hwnd = GetDesktopWindow();

	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, generatedPassword.size() + 1);
	if (!hg)
	{
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), generatedPassword.c_str(), generatedPassword.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);*/
}
