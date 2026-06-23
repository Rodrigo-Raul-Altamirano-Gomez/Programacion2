cmake_minimum_required(VERSION 4.2)
project(Pregunta01)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta01 main.cpp
        Bibliotecas/Persona.cpp
        Bibliotecas/Persona.h
        Bibliotecas/Alumno.cpp
        Bibliotecas/Alumno.h
        Bibliotecas/Profesor.cpp
        Bibliotecas/Profesor.h)
