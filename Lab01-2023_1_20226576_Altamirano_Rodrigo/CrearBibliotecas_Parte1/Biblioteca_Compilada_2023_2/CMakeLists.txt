cmake_minimum_required(VERSION 4.2)
project(Biblioteca_Compilada_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_library(OperadoresSobrecargados STATIC Bibliotecas/OperadoresSobrecargados.cpp)

add_executable(Biblioteca_Compilada_2023_2 main.cpp
        Bibliotecas/OperadoresSobrecargados.cpp)

target_link_libraries(Biblioteca_Compilada_2023_2 OperadoresSobrecargados)
