//
// Created by hrodic on 2/06/2026.
//

#ifndef STREAMERS_HERENCIA_STREAMERGRATUITO_H
#define STREAMERS_HERENCIA_STREAMERGRATUITO_H

#include "Streamer.h"
#include "MetricaBasica.h"

class StreamerGratuito : public Streamer {
    int fecha_fin_trial;
    MetricaBasica* metricas_basicas;
    int cantidad_metricas_basicas;
public:
    StreamerGratuito();
    StreamerGratuito(const StreamerGratuito&);
    StreamerGratuito& operator=(const StreamerGratuito&);
    void setMetricasBasicas(const MetricaBasica*,int);
    int get_fecha_fin_trial() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    void imprimir_metricas_basicas(ofstream&,int&,int&) const;
    void obtener_metricas_basicas_general(double&,int&,int&,int&) const;
    void insertarMetricaBasica(const MetricaBasica&);
    ~StreamerGratuito();
};

ifstream& operator>>(ifstream&,StreamerGratuito&);
ofstream& operator<<(ofstream&,const StreamerGratuito&);

#endif //STREAMERS_HERENCIA_STREAMERGRATUITO_H
