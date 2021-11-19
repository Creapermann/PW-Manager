cmake_minimum_required(VERSION 3.9)

project(PW-Manager VERSION 1.0)

# language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_subdirectory(libs/FTXUI)
add_subdirectory(libs/clip)
add_subdirectory(libs/sqlite3)

                  
                  
add_executable(app src/Main.cpp
                   src/Shared.h
                   
                   # MODEL
                   src/Model/CopyToClipboard.cpp
                   src/Model/CopyToClipboard.h
                   src/Model/DatabaseManager.h
                   src/Model/DatabaseManager.cpp
                   src/Model/FtxuiIncludes.h
                   src/Model/Note.cpp
                   src/Model/Note.h
                   src/Model/ProgramInfo.h
                   src/Model/User.h
                   
                   # VIEW
                   src/View/UI_AddNote.cpp
                   src/View/UI_AddNote.h
                   src/View/UI_ConfirmDelete.h
                   src/View/UI_EditNote.cpp
                   src/View/UI_Login.h
                   src/View/UI_MenuSettings.cpp
                   src/View/UI_Signup.h
                   src/View/UI_Credits.cpp
                   src/View/UI_EditNote.h
                   src/View/UI_Menu.cpp
                   src/View/UI_MenuSettings.h
                   src/View/UI_Start.cpp
                   src/View/UI_ConfirmDelete.cpp
                   src/View/UI_Credits.h
                   src/View/UI_Login.cpp
                   src/View/UI_Menu.h
                   src/View/UI_Signup.cpp
                   src/View/UI_Start.h
                   
                   # VIEWMODEL
                   src/ViewModel/Edit.cpp
                   src/ViewModel/Edit.h
                   src/ViewModel/Login.cpp
                   src/ViewModel/Login.h
                   src/ViewModel/Menu.cpp
                   src/ViewModel/Menu.h
                   src/ViewModel/Signup.cpp
                   src/ViewModel/Signup.h
    )


target_include_directories(app 
                               # OWN
                               PRIVATE src/
                               PRIVATE src/View
                               PRIVATE src/Model
                               PRIVATE src/ViewModel
                               
                               # FTXUI
                               PRIVATE inc/FTXUI/component
                               PRIVATE inc/FTXUI/dom
                               PRIVATE inc/FTXUI/screen
                               PRIVATE inc/FTXUI/util
                               
                               # CLIP
                               PRIVATE inc/clip
                               
                               # SQLITE
                               PRIVATE inc/sqlite
    )


target_link_libraries(app
                          # FTXUI
                          screen
                          dom
                          component
                          
                          # CLIP
                          clip
                          
                          # SQLITE
                          sqlite
    )