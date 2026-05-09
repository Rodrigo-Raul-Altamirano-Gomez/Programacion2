cmake_minimum_required(VERSION 4.2)
project(LAB06_PREG02_BIBLIOTECA)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB06_PREG02_BIBLIOTECA main.cpp
        Biblioteca.cpp
        Estante.cpp
        Libro.cpp
        Espacio.cpp)
