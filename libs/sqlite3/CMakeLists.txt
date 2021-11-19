cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


add_library(sqlite STATIC
                   src/sqlite3.c
                   src/sqlite3.h
                   src/sqlite3ext.h
                   src/shell.c
    )


if(UNIX)
    target_link_libraries(sqlite PRIVATE ${PROJECT_SOURCE_DIR}/libs/libdl/libdl.so)
endif()