cmake_minimum_required(VERSION 4.2)
project(ListaGenerica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaGenerica main.cpp
        BibliotecaGenerica.cpp
        BibliotecaGenerica.h
        FuncionesEnteras.cpp
        FuncionesEnteras.h
        FuncionesRegistros.cpp
        FuncionesRegistros.h)
