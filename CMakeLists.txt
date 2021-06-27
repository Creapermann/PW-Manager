# CMakeList.txt : CMake project for PW-Manager, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# ------------------------------------------------------------------------------

project ("PW-Manager"
  LANGUAGES CXX
  VERSION 1.0.0
  )

# Add source to this project's executable.
add_executable (PW-Manager "src/PW-Manager.cpp" "src/PW-Manager.h")
set_target_properties(PW-Manager PROPERTIES CXX_STANDARD 17)

target_include_directories(PW-Manager PRIVATE src)
target_link_libraries(PW-Manager
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)