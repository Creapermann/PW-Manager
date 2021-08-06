# CMakeList.txt : CMake project for PW-Manager, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PW-Manager"
  LANGUAGES CXX
  VERSION 0.1.0
  )

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

find_package(sqlite3)


# Add source to this project's executable.
add_executable (PW-Manager  "src/Model/ProgramInfo.h"
							"src/Main.cpp"
							"src/View/UI_Start.cpp"
							"src/View/UI_Start.h" 
							"src/Model/FtxuiIncludes.h" 
							"src/View/UI_Login.cpp" 
							"src/View/UI_Login.h" 
							"src/View/UI_Signup.h" 
							"src/View/UI_Signup.cpp" 
							"src/ViewModel/Login.cpp" 
							"src/ViewModel/Login.h"   
							"lib/pwstring.cpp" 
							"src/ViewModel/Signup.cpp" 
							"src/ViewModel/Signup.h" 
							"src/View/UI_Credits.cpp" 
							"src/View/UI_Credits.h" 
							"src/Model/DatabaseManager.h"
							"src/Model/DatabaseManager.cpp" 
		   				    "src/View/UI_Menu.cpp" 
						    "src/View/UI_Menu.h"
							"src/View/UI_Settings.h"
							"src/View/UI_Settings.cpp"
						    "src/ViewModel/Menu.cpp"  
						    "src/Model/User.h" 
						    "src/Shared.h" 
						    "src/View/UI_AddNote.cpp"
						    "src/View/UI_AddNote.h" "src/View/UI_EditNote.cpp" "src/View/UI_EditNote.h" "src/ViewModel/Edit.cpp" "src/ViewModel/Edit.h")

set_target_properties(PW-Manager PROPERTIES CXX_STANDARD 17)
target_compile_features(PW-Manager PRIVATE cxx_std_17)
target_compile_options(PW-Manager PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>)

target_include_directories(PW-Manager PRIVATE src/ lib/)
target_link_libraries(PW-Manager
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  clip
  sqlite3
  )

  # Disable clip examples and tests
set(CLIP_EXAMPLES OFF CACHE BOOL "Compile clip examples")
set(CLIP_TESTS OFF CACHE BOOL "Compile clip tests")

# In case that you have ${PNG_LIBRARY} set to support copy/paste images on Linux
#set(CLIP_X11_PNG_LIBRARY "${PNG_LIBRARY}")

# Add clip subdirectory to compile the library
add_subdirectory(lib/clip)