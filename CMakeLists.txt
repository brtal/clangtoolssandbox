cmake_minimum_required(VERSION 3.17)
project (clangtoolstest)

find_program(CLANG_TIDY clang-tidy)
if (NOT CLANG_TIDY)
	message(FATAL_ERROR "clang-tidy not found")
endif()

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clangtoolstest src/main.cpp src/tidy_copies.cpp)
