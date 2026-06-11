cmake_minimum_required(VERSION 4.2)
project(PREG02)

set(CMAKE_CXX_STANDARD 20)

add_executable(PREG02 main.cpp
        Bibliotecas/Producto.cpp
        Bibliotecas/Restaurante.cpp
        Bibliotecas/PlatoFondo.cpp
        Bibliotecas/Entrada.cpp
        Bibliotecas/Comanda.cpp
        Bibliotecas/Bebida.cpp)
