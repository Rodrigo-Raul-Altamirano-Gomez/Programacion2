cmake_minimum_required(VERSION 4.2)
project(UnaAplicacionConBibEsattica)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

add_executable(UnaAplicacionConBibEsattica main.cpp
        Bibliotecas/OperadoresSobrecargados.h
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h)

target_link_libraries(UnaAplicacionConBibEsattica PRIVATE BibliotecaCompilada_2024_1)
