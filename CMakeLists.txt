cmake_minimum_required(VERSION 3.16)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "clang++")

project("calc" LANGUAGES CXX VERSION 1.0.1 DESCRIPTION "Simple calculator" HOMEPAGE_URL "https://github/FTS427/calc_cpp/" )

set(CMAKE_CXX_STANDARD 17)

include_directories("src/include")
aux_source_directory("src" SRC)

add_executable(${PROJECT_NAME} ${SRC})
