# CMakeList.txt : CMake project for mutex, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("mutex")

# Add source to this project's executable.
add_executable (mutex "mutex.cpp" "mutex.h")

# TODO: Add tests and install targets if needed.
