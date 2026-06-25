cmake_minimum_required(VERSION 4.2)
project(LAB09_ABBSTL)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB09_ABBSTL main.cpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.h
        Bibliotecas/Enciclopedia.cpp
        Bibliotecas/Enciclopedia.h
        Bibliotecas/Revista.cpp
        Bibliotecas/Revista.h
        Bibliotecas/Novela.cpp
        Bibliotecas/Novela.h
        Bibliotecas/NLibro.cpp
        Bibliotecas/NLibro.h
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.h
        Bibliotecas/NodoArbol.h
        Bibliotecas/ABB.h
        Bibliotecas/Biblioteca.cpp
        Bibliotecas/Biblioteca.h)
