cmake_minimum_required(VERSION 4.2)
project(Fuentes_Biblioteca_2023_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

add_executable(Fuentes_Biblioteca_2023_2 main.cpp
        Bibliotecas/OperadoresSobrecargados.cpp
        Bibliotecas/OperadoresSobrecargados.h
        Bibliotecas/Estructuras.h
        Bibliotecas/AperturaDeArchivos.h
        Bibliotecas/MainAuxiliares.cpp
        Bibliotecas/MainAuxiliares.h)

target_link_libraries(Fuentes_Biblioteca_2023_2 PRIVATE AperturaDeArchivos)
