cmake_minimum_required(VERSION 4.2)
project(LAB06_PREG01_CLASES)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB06_PREG01_CLASES main.cpp
        ProductoEntregado.cpp
        ProductoEntregado.h
        Cliente.cpp
        Cliente.h
        Producto.cpp
        Producto.h
        Pedido.cpp
        Pedido.h
        Almacen.h
        FuncionesAuxiliares.cpp
        FuncionesAuxiliares.h)
