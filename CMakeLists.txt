cmake_minimum_required(VERSION 3.13)
project(os_homework C)

set(CMAKE_C_STANDARD 11)

add_executable(os_homework week12/ex1.c week12/ex2.c week12/ex3_helper.c)
find_package(Threads REQUIRED)
target_link_libraries(os_homework PRIVATE Threads::Threads)
