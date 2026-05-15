cmake_minimum_required(VERSION 4.2)
project(CLASES_OBJETOS_OPERADORES_SOBRECARGADOS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLASES_OBJETOS_OPERADORES_SOBRECARGADOS main.cpp
        Cliente.cpp
        Cliente.h
        Plato.cpp
        Plato.h
        Restaurante.cpp
        Restaurante.h)
