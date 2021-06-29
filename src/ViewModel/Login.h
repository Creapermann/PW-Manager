#pragma once

#include "../View/UI_Start.h"

#include <iostream>

class Login {

public:
  std::wstring email;
  std::wstring password;

public:
  void loginButtonClick(std::wstring email, std::wstring password);
  void menuButtonClick();
};