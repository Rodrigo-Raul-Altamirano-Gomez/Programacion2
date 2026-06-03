cmake_minimum_required(VERSION 4.2)
project(Streamers_Herencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Streamers_Herencia main.cpp
        Bibliotecas/Metrica.cpp
        Bibliotecas/Metrica.h
        Bibliotecas/MetricaBasica.cpp
        Bibliotecas/MetricaBasica.h
        Bibliotecas/MetricaEngagement.cpp
        Bibliotecas/MetricaEngagement.h
        Bibliotecas/MetricaCalidad.cpp
        Bibliotecas/MetricaCalidad.h
        Bibliotecas/Streamer.cpp
        Bibliotecas/Streamer.h
        Bibliotecas/StreamerGratuito.cpp
        Bibliotecas/StreamerGratuito.h
        Bibliotecas/StreamerPago.cpp
        Bibliotecas/StreamerPago.h
        Bibliotecas/GestorStreamers.cpp
        Bibliotecas/GestorStreamers.h)
