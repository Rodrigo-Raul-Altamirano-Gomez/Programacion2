cmake_minimum_required(VERSION 4.2)
project(HERENCIA)

set(CMAKE_CXX_STANDARD 20)

add_executable(HERENCIA main.cpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.h
        Bibliotecas/Drone.cpp
        Bibliotecas/Drone.h
        Bibliotecas/DroneVelocidad.cpp
        Bibliotecas/DroneVelocidad.h
        Bibliotecas/DroneSemaforo.cpp
        Bibliotecas/DroneSemaforo.h
        Bibliotecas/DroneEstacionamiento.cpp
        Bibliotecas/DroneEstacionamiento.h
        Bibliotecas/Flota.cpp
        Bibliotecas/Flota.h
        Bibliotecas/CentralDeMonitoreo.cpp
        Bibliotecas/CentralDeMonitoreo.h
        Bibliotecas/MinisterioDeTransportes.cpp
        Bibliotecas/MinisterioDeTransportes.h)
