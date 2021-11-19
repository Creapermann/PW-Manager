#pragma once

#include "UI_Start.h"

#include <iostream>
#include <string>


class Signup {

public:
	std::wstring firstname;
	std::wstring lastname;
	std::wstring email;
	std::wstring password;
	std::wstring confirmPassword;

public:
	void signupButtonClick(std::wstring& e_first);
	void menuButtonClick();
};