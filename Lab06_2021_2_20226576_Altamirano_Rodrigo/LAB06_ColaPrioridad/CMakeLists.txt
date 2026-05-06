cmake_minimum_required(VERSION 4.2)
project(LAB06_ColaPrioridad)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB06_ColaPrioridad main.cpp
        BibGenerica.cpp
        BibGenerica.h
        BibImpresion.cpp
        BibImpresion.h
        FunConRegistros.cpp
        FunConRegistros.h
        FunConEnteros.cpp
        FunConEnteros.h)
