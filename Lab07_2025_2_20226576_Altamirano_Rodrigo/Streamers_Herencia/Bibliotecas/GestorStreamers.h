//
// Created by hrodic on 2/06/2026.
//

#ifndef STREAMERS_HERENCIA_GESTORSTREAMERS_H
#define STREAMERS_HERENCIA_GESTORSTREAMERS_H

#include "StreamerGratuito.h"
#include "StreamerPago.h"

class GestorStreamers {
    StreamerGratuito* streamers_gratuitos;
    StreamerPago* streamers_pagados;
    int cantidad_gratuitos;
    int cantidad_pagados;
public:
    GestorStreamers();
    void setStreamersGratuitos(StreamerGratuito*,int);
    void setStreamersPagados(StreamerPago*,int);
    void setCantidadGratuitos(int);
    void setCantidadPagados(int);
    StreamerGratuito* getStreamersGratuitos() const;
    StreamerPago* getStreamersPagados() const;
    int getCantidadGratuitos() const;
    int getCantidadPagados() const;
    void cargar_datos_streamers(const char*);
    void actualizar_datos_metricas(const char*);
    void buscarStreamer(int,int&,char&);
    void generar_reporte();
};


#endif //STREAMERS_HERENCIA_GESTORSTREAMERS_H
