cmake_minimum_required(VERSION 4.2)
project(LAB07_BIBLIOTECA_HERENCIA)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB07_BIBLIOTECA_HERENCIA main.cpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.h
        Bibliotecas/Enciclopedia.cpp
        Bibliotecas/Enciclopedia.h
        Bibliotecas/Novela.cpp
        Bibliotecas/Novela.h
        Bibliotecas/Espacio.cpp
        Bibliotecas/Espacio.h
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.h
        Bibliotecas/EstanteVertical.cpp
        Bibliotecas/EstanteVertical.h
        Bibliotecas/EstanteHorizontal.cpp
        Bibliotecas/EstanteHorizontal.h
        Bibliotecas/Biblioteca.cpp
        Bibliotecas/Biblioteca.h)
