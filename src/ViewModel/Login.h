#pragma once

#include "UI_Start.h"

#include <iostream>

class Login {

public:
	std::wstring email{};
	std::wstring password{};

public:
  void loginButtonClick(std::wstring& e_first);
  void menuButtonClick();
};