cmake_minimum_required(VERSION 3.16)

project("calc")

set(CMAKE_CXX_STANDARD 17)

include_directories("src/include")
aux_source_directory("src" SRC)

add_executable(${PROJECT_NAME} ${SRC})
