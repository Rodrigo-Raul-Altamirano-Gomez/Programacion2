//
// Created by hrodic on 1/06/2026.
//

#ifndef STREAMERS_HERENCIA_METRICACALIDAD_H
#define STREAMERS_HERENCIA_METRICACALIDAD_H

#include "Metrica.h"

class MetricaCalidad : public Metrica {
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int  fps_promedio;
public:
    MetricaCalidad() = default;
    MetricaCalidad(const MetricaCalidad&);
    MetricaCalidad& operator=(const MetricaCalidad&);
    void setBitratePromedio(int);
    void setPorcentajePerdidaFrames(double);
    void setFpsPromedio(int);
    int getBitratePromedio() const;
    double getPorcentajePerdidaFrames() const;
    int getFpsPormedio() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~MetricaCalidad() = default;
};

ifstream& operator>>(ifstream&,MetricaCalidad&);
ofstream& operator<<(ofstream&,const MetricaCalidad&);

#endif //STREAMERS_HERENCIA_METRICACALIDAD_H
