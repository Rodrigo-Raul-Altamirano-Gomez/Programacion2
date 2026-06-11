//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_DRONESEMAFORO_H
#define HERENCIA_DRONESEMAFORO_H

#include "Drone.h"

class DroneSemaforo : public Drone {
    int luz_roja;
public:
    int get_luz_roja() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
};

ifstream& operator>>(ifstream&,DroneSemaforo&);
ofstream& operator<<(ofstream&,const DroneSemaforo&);

#endif //HERENCIA_DRONESEMAFORO_H
