cmake_minimum_required(VERSION 4.2)
project(PREG02_LAB08)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG02_LAB08 main.cpp
        Bibliotecas/Bebida.cpp
        Bibliotecas/Cola.cpp
        Bibliotecas/DetalleComanda.cpp
        Bibliotecas/Entrada.cpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/PlatoFondo.cpp
        Bibliotecas/Producto.cpp
        Bibliotecas/Restaurante.cpp)
