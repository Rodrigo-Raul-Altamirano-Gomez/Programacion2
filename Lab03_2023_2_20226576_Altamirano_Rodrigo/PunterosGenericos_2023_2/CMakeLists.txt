cmake_minimum_required(VERSION 4.2)
project(PunterosGenericos_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosGenericos_2023_2 main.cpp
        Bibliotecas/MuestraPunteros.h
        Bibliotecas/MuestraPunteros.cpp
        Bibliotecas/PunterosGenericos.cpp
        Bibliotecas/PunterosGenericos.h)
