cmake_minimum_required(VERSION 4.2)
project(PREG01_LAB09)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG01_LAB09 main.cpp
        Bibliotecas/Palabra.cpp
        Bibliotecas/Palabra.h
        Bibliotecas/Oracion.cpp
        Bibliotecas/Oracion.h
        Bibliotecas/AnalisisSentimiento.cpp
        Bibliotecas/AnalisisSentimiento.h)
