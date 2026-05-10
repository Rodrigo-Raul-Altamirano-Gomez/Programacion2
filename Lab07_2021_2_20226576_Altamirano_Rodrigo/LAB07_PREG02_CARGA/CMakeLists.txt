cmake_minimum_required(VERSION 4.2)
project(LAB07_PREG02_CARGA)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB07_PREG02_CARGA main.cpp
        Libro.cpp
        LibroPrestado.cpp
        Usuario.cpp
        Funciones.cpp
        Funciones.h)
