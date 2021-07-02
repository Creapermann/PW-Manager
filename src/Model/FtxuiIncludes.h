// PW-Manager.h : Include file for standard system include files,
// or project specific include files.

#pragma once

// Standard Library
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

// FTXUI Library
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/input.hpp>
#include <ftxui/component/menu.hpp>
#include <ftxui/component/screen_interactive.hpp>

// SQLite3 Library
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <winsqlite/winsqlite3.h>
#elif __linux__
#include <sqlite/sqlite3.h>
#endif

// TODO: Reference additional headers your program requires here.