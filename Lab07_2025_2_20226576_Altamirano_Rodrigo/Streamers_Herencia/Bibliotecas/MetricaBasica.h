//
// Created by hrodic on 1/06/2026.
//

#ifndef STREAMERS_HERENCIA_METRICABASICA_H
#define STREAMERS_HERENCIA_METRICABASICA_H

#include "Metrica.h"

class MetricaBasica : public Metrica {
    double horas_transmitidas;
    int espectadores_promedio;
public:
    MetricaBasica() = default;
    MetricaBasica(const MetricaBasica&);
    MetricaBasica& operator=(const MetricaBasica&);
    void setHorasTrans(double);
    void setEspecProm(int);
    double getHorasTrans() const;
    int getEspecProm() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~MetricaBasica() = default;
};

ifstream& operator>>(ifstream&,MetricaBasica&);
ofstream& operator<<(ofstream&,const MetricaBasica&);

#endif //STREAMERS_HERENCIA_METRICABASICA_H
