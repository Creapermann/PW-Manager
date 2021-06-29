#pragma once

#include "../View/UI_Start.h"

#include <iostream>

class Signup {

public:
	std::wstring firstname;
	std::wstring lastname;
	std::wstring email;
	std::wstring password;
	std::wstring confirmPassword;

public:
	void signupButtonClick(std::wstring firstname, std::wstring lastname, std::wstring email, std::wstring password, std::wstring confirmPassword);
	void menuButtonClick();
};