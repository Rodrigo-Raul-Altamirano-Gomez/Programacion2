//
// Created by hrodic on 2/06/2026.
//

#ifndef STREAMERS_HERENCIA_STREAMERPAGO_H
#define STREAMERS_HERENCIA_STREAMERPAGO_H

#include "MetricaBasica.h"
#include "MetricaEngagement.h"
#include "MetricaCalidad.h"
#include "Streamer.h"

class StreamerPago : public Streamer {
    int fecha_inicio_plan;
    MetricaBasica* metricas_basicas;
    int cantidad_metricas_basicas;
    MetricaEngagement* metricas_engagements;
    int cantidad_metricas_engagement;
    MetricaCalidad* metricas_calidades;
    int cantidad_metricas_calidades;
public:
    StreamerPago();
    StreamerPago(const StreamerPago&);
    StreamerPago& operator=(const StreamerPago&);
    void setMetricasBasicas(const MetricaBasica*,int);
    void setMetricasEngagement(const MetricaEngagement*,int);
    void setMetricasCalidad(const MetricaCalidad*,int);
    int get_fecha_inicio_plan() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    void imprimir_metricas_basicas(ofstream&,int&,int&) const;
    void obtener_metricas_basicas_general(double&,int&,int&,int&) const;
    void imprimir_metricas_engagement(ofstream&,int&,int&) const;
    void obtener_metricas_engagement_general(int&,int&,int&,int&,int&) const;
    void imprimir_metricas_calidad(ofstream&,int&,int&) const;
    void obtener_metricas_calidad_general(int&,double&,int&,int&,int&) const;
    void insertarMetricaBasica(const MetricaBasica&);
    void insertar_metrica_engagement(const MetricaEngagement&);
    void insertar_metrica_calidad(const MetricaCalidad&);
    ~StreamerPago();
};

ifstream& operator>>(ifstream&,StreamerPago&);
ofstream& operator<<(ofstream&,const StreamerPago&);

#endif //STREAMERS_HERENCIA_STREAMERPAGO_H
