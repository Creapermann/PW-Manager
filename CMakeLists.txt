# CMakeList.txt : CMake project for PW-Manager, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PW-Manager")

# Add source to this project's executable.
add_executable (PW-Manager "src/PW-Manager.cpp" "src/PW-Manager.h")

# TODO: Add tests and install targets if needed.
