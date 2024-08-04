cmake_minimum_required(VERSION 3.28)

project(sha1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDSARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_COLOR_DIAGNOSTICS On)
add_compile_options(-Wall -Wextra -Wpedantic)

set(PROJECT_MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)

add_executable(sha1)
target_sources(sha1 PUBLIC
                 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_sources(sha1 PRIVATE
               FILE_SET modules TYPE CXX_MODULES
               FILES
                 ${CMAKE_CURRENT_SOURCE_DIR}/sha1.cppm
)
