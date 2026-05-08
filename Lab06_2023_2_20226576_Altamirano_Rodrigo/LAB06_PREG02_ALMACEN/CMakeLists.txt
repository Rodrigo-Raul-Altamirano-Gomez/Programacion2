cmake_minimum_required(VERSION 4.2)
project(LAB06_PREG02_ALMACEN)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB06_PREG02_ALMACEN main.cpp
        Cliente.cpp
        FuncionesAuxiliares.cpp
        Pedido.cpp
        Producto.cpp
        ProductoEntregado.cpp
        Almacen.cpp
)
