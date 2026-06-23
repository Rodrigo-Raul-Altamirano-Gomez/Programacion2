cmake_minimum_required(VERSION 4.2)
project(LAB09_PREG02)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB09_PREG02 main.cpp
        Bibliotecas/Camion.cpp
        Bibliotecas/Flota.cpp
        Bibliotecas/Furgon.cpp
        Bibliotecas/NPedido.cpp
        Bibliotecas/NVehiculo.cpp
        Bibliotecas/Vehiculo.cpp)
