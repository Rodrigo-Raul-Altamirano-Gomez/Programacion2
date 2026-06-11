//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_DRONEESTACIONAMIENTO_H
#define HERENCIA_DRONEESTACIONAMIENTO_H

#include "Drone.h"

class DroneEstacionamiento : public Drone {
    int zona_carga;
public:
    int get_zona_carga() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
};

ifstream& operator>>(ifstream&,DroneEstacionamiento&);
ofstream& operator<<(ofstream&,const DroneEstacionamiento&);

#endif //HERENCIA_DRONEESTACIONAMIENTO_H
