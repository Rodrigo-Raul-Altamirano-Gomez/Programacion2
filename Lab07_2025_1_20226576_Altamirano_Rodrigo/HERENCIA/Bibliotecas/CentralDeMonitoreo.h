//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_CENTRALDEMONITOREO_H
#define HERENCIA_CENTRALDEMONITOREO_H

#include "Flota.h"

class CentralDeMonitoreo {
    Flota flota;
    int cantidad_multas_registradas;
    double total_multas_acumuladas;
public:
    CentralDeMonitoreo();
    void leer(ifstream&,const char*);
    void cargar_infracciones(ifstream&);
    void imprimir(ofstream&) const;
};

ofstream& operator<<(ofstream&,const CentralDeMonitoreo&);

#endif //HERENCIA_CENTRALDEMONITOREO_H
