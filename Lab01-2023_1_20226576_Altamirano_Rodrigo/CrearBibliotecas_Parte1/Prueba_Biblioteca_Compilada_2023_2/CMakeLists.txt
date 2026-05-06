cmake_minimum_required(VERSION 4.2)
project(Prueba_Biblioteca_Compilada_2023_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

add_executable(Prueba_Biblioteca_Compilada_2023_2 main.cpp)

target_link_libraries(Prueba_Biblioteca_Compilada_2023_2 PRIVATE AperturaDeArchivos OperadoresSobrecargados)