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
  VERSION 0.1.0
  )

# Add source to this project's executable.
add_executable (PW-Manager  "src/Model/ProgramInfo.h"
							"src/Main.cpp"
							"src/View/UI_Start.cpp"
							"src/View/UI_Start.h" 
							"src/Model/FtxuiIncludes.h" 
							"src/View/UI_Login.cpp" 
							"src/View/UI_Login.h" 
							"src/View/UI_Register.h" 
							"src/View/UI_Register.cpp" "src/ViewModel/Login.cpp" "src/ViewModel/Login.h")

set_target_properties(PW-Manager PROPERTIES CXX_STANDARD 17)
target_compile_features(PW-Manager PRIVATE cxx_std_17)
target_compile_options(PW-Manager PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>)

target_include_directories(PW-Manager PRIVATE src)
target_link_libraries(PW-Manager
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)