cmake_minimum_required(VERSION 4.2)
project(LAB08_PREG01)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB08_PREG01 main.cpp
        Bibliotecas/NPedido.cpp
        Bibliotecas/NPedido.h
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.h
        Bibliotecas/Camion.cpp
        Bibliotecas/Camion.h
        Bibliotecas/Furgon.cpp
        Bibliotecas/Furgon.h
        Bibliotecas/NodoLista.cpp
        Bibliotecas/NodoLista.h
        Bibliotecas/LVehiculos.cpp
        Bibliotecas/LVehiculos.h
        Bibliotecas/Flota.cpp
        Bibliotecas/Flota.h)
