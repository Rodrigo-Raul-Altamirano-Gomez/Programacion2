cmake_minimum_required(VERSION 4.2)
project(LAB08_POLITAD)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB08_POLITAD main.cpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.h
        Bibliotecas/Enciclopedia.cpp
        Bibliotecas/Enciclopedia.h
        Bibliotecas/Revista.cpp
        Bibliotecas/Revista.h
        Bibliotecas/Novela.cpp
        Bibliotecas/Novela.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.h
        Bibliotecas/Estante.cpp
        Bibliotecas/Estante.h
        Bibliotecas/Biblioteca.cpp
        Bibliotecas/Biblioteca.h)
