cmake_minimum_required(VERSION 3.13)
project(os_homework C)

set(CMAKE_C_STANDARD 11)

add_executable(os_homework week09/ex1.c #[[week09/generator.c]])
find_package(Threads REQUIRED)
target_link_libraries(os_homework PRIVATE Threads::Threads)
