cmake_minimum_required(VERSION 4.2)
project(LAB09_PREG01)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB09_PREG01 main.cpp
        Bibliotecas/NPedido.cpp
        Bibliotecas/NPedido.h
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.h
        Bibliotecas/Camion.cpp
        Bibliotecas/Camion.h
        Bibliotecas/Furgon.cpp
        Bibliotecas/Furgon.h
        Bibliotecas/NVehiculo.cpp
        Bibliotecas/NVehiculo.h
        Bibliotecas/Flota.cpp
        Bibliotecas/Flota.h)
