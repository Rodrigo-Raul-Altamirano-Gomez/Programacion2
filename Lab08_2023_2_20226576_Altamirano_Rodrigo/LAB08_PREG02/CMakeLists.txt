cmake_minimum_required(VERSION 4.2)
project(LAB08_PREG02)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB08_PREG02 main.cpp
        Bibliotecas/Camion.cpp
        Bibliotecas/Flota.cpp
        Bibliotecas/Furgon.cpp
        Bibliotecas/LVehiculos.cpp
        Bibliotecas/NodoLista.cpp
        Bibliotecas/NPedido.cpp
        Bibliotecas/Vehiculo.cpp)
