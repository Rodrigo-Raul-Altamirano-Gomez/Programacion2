cmake_minimum_required(VERSION 4.2)
project(PREG02_LAB09)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG02_LAB09 main.cpp
        Bibliotecas/AnalisisSentimiento.cpp
        Bibliotecas/Oracion.cpp
        Bibliotecas/Palabra.cpp)
