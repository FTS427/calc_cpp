cmake_minimum_required(VERSION 3.16)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "clang++")

project("calc" LANGUAGES CXX VERSION 1.0.1 DESCRIPTION "Simple calculator" HOMEPAGE_URL "https://github.com/FTS427/calc_cpp")

set(CMAKE_CXX_STANDARD 17)

include_directories("src/include")
aux_source_directory("src" SRC)

add_executable(${PROJECT_NAME} ${SRC})

add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")
add_definitions(-DPROJECT_VERSION="${PROJECT_VERSION}")
add_definitions(-DPROJECT_REPO="${PROJECT_HOMEPAGE_URL}")
add_definitions(-DPROJECT_LICENSE="GPL-3.0")
add_definitions(-DPROJECT_DESCRIPTION="${PROJECT_DESCRIPTION}")
add_definitions(-DPROJECT_AUTHOR="Huang FTS427")