cmake_minimum_required(VERSION 4.2)
project(LAB07_PREG01_CLASES)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB07_PREG01_CLASES main.cpp
        Conductor.cpp
        Conductor.h
        FaltaCond.cpp
        FaltaCond.h
        Falta.cpp
        Falta.h
        Infraccion.cpp
        Infraccion.h)
