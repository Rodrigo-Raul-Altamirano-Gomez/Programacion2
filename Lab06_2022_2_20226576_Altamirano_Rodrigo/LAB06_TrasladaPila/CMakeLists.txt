cmake_minimum_required(VERSION 4.2)
project(LAB06_TrasladaPila)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB06_TrasladaPila main.cpp
        BibliotecaPilaGenerica.cpp
        BibliotecaPilaGenerica.h
        PilaConEnteros.cpp
        PilaConEnteros.h
        PilaConRegistros.cpp
        PilaConRegistros.h)
