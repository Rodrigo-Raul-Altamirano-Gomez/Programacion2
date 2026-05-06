cmake_minimum_required(VERSION 4.2)
project(LaboratorioIntegrador)

set(CMAKE_CXX_STANDARD 20)

add_executable(LaboratorioIntegrador main.cpp
        BibliotecaGenerica.cpp
        BibliotecaGenerica.h
        BibliotecaConductores.cpp
        BibliotecaConductores.h
        BibliotecaInfracciones.cpp
        BibliotecaInfracciones.h)
