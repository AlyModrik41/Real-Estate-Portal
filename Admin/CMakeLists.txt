cmake_minimum_required(VERSION 3.16)
project(Admin)

set(CMAKE_CXX_STANDARD 20)

add_executable(Admin
        test.cpp
        admin.cpp
        properties.cpp
)