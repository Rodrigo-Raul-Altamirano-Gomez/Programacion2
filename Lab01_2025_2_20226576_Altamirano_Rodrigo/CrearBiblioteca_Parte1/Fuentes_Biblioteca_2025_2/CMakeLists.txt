cmake_minimum_required(VERSION 4.2)
project(Fuentes_Biblioteca_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_library(OperadoresSobrecargados Bibliotecas/OperadoresSobrecargados.cpp)

add_executable(Fuentes_Biblioteca_2025_2 main.cpp
        Bibliotecas/Estructuras.h
        Bibliotecas/OperadoresSobrecargados.cpp
        Bibliotecas/OperadoresSobrecargados.h)

target_link_libraries(Fuentes_Biblioteca_2025_2 OperadoresSobrecargados)
