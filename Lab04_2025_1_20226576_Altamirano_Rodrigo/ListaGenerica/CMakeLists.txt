cmake_minimum_required(VERSION 4.2)
project(ListaGenerica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaGenerica main.cpp
        BibliotecaGenerica.cpp
        BibliotecaRegistros.cpp
        BibliotecaRegistros.h
        BibliotecaEnteros.cpp
        BibliotecaEnteros.h
        BibliotecaGenerica.h)
