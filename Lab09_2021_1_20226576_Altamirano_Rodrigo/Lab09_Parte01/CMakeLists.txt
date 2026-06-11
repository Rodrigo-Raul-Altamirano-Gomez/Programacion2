cmake_minimum_required(VERSION 4.2)
project(Infracciones2021_1Lab09)

set(CMAKE_CXX_STANDARD 20)

add_executable(Infracciones2021_1Lab09 main.cpp
        Bibliotecas/Conductor.cpp
        Bibliotecas/Conductor.h
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.h
        Bibliotecas/Falta.cpp
        Bibliotecas/Falta.h
        Bibliotecas/Leve.cpp
        Bibliotecas/Leve.h
        Bibliotecas/Grave.cpp
        Bibliotecas/Grave.h
        Bibliotecas/MuyGrave.cpp
        Bibliotecas/MuyGrave.h
        Bibliotecas/Registro.cpp
        Bibliotecas/Registro.h
        Bibliotecas/Procesa.cpp
        Bibliotecas/Procesa.h)
