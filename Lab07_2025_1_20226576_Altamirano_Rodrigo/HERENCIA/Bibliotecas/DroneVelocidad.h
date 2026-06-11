//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_DRONEVELOCIDAD_H
#define HERENCIA_DRONEVELOCIDAD_H

#include "Drone.h"

class DroneVelocidad : public Drone {
    int velocidad_maxima_permitida;
public:
    int get_velocidad_maxima() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
};

ifstream& operator>>(ifstream&,DroneVelocidad&);
ofstream& operator<<(ofstream&,const DroneVelocidad&);

#endif //HERENCIA_DRONEVELOCIDAD_H
