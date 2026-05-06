cmake_minimum_required(VERSION 4.2)
project(BibEstaticaEnUnaAplicacion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

add_executable(BibEstaticaEnUnaAplicacion main.cpp
        Bibliotecas/AperturaDeArchivos.h
        Bibliotecas/Estructuras.h
        Bibliotecas/OperadoresSobrecargados.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.h)

target_link_libraries(BibEstaticaEnUnaAplicacion PRIVATE AperturaDeArchivos OperadoresSobrecargados)
