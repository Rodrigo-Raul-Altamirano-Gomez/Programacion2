cmake_minimum_required(VERSION 4.2)
project(PREG02_LAB09)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG02_LAB09 main.cpp
        Bibliotecas/Alumno.cpp
        Bibliotecas/Boleta.cpp
        Bibliotecas/Escala.cpp
        Bibliotecas/Presencial.cpp
        Bibliotecas/Semipresencial.cpp
        Bibliotecas/Tesoreria.cpp
        Bibliotecas/Virtual.cpp)
