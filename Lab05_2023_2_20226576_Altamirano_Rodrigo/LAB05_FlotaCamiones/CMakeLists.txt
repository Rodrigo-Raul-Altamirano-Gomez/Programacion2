cmake_minimum_required(VERSION 4.2)
project(LAB05_FlotaCamiones)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB05_FlotaCamiones main.cpp
        PilaConEnteros.cpp
        PilaConEnteros.h
        PilaConRegistros.cpp
        PilaConRegistros.h
        FlotaGenerica.cpp
        FlotaGenerica.h)
