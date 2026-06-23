cmake_minimum_required(VERSION 4.2)
project(Pregunta04)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta04 main.cpp
        Bibliotecas/Alumno.cpp
        Bibliotecas/Aula.cpp
        Bibliotecas/NodoCola.h
        Bibliotecas/Persona.cpp
        Bibliotecas/PlCola.h
        Bibliotecas/Profesor.cpp
        Bibliotecas/Reserva.cpp
        Bibliotecas/Reserva.h)
