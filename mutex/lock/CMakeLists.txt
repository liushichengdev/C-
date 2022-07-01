# CMakeList.txt : CMake project for lock, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("lock")

# Add source to this project's executable.
add_executable (lock "lock.cpp" "lock.h")

# TODO: Add tests and install targets if needed.
