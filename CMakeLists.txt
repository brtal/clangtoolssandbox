cmake_minimum_required(VERSION 3.17)
project (clangtoolstest)

find_program(CLANG_TIDY clang-tidy)
if (NOT CLANG_TIDY)
	message(FATAL_ERROR "clang-tidy not found")
endif()

option(CLANG_TIDY_FIX "whether to fix clang-tidy errors" OFF)

if (CLANG_TIDY_FIX)
	set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY}" "-fix")
else()
	set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY}")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")

add_executable(clangtoolstest src/main.cpp src/tidy_copies.cpp)
