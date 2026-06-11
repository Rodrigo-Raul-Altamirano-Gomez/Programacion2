//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_FLOTA_H
#define HERENCIA_FLOTA_H

#include "DroneVelocidad.h"
#include "DroneSemaforo.h"
#include "DroneEstacionamiento.h"

class Flota {
    DroneVelocidad drones_velocidad[20];
    DroneSemaforo drones_semaforo[20];
    DroneEstacionamiento drones_estacionamiento[20];
    int n_drones_velocidad;
    int n_drones_semaforo;
    int n_drones_estacionamiento;
public:
    Flota();
    void cargar_drone(ifstream&,const char*);
    int buscarDroneVelocidad(const char*);
    int buscarDroneSemaforo(const char*);
    int buscarDroneEstacionamiento(const char*);
    void actualizarDronesInfracciones(ifstream&);
    void obtener_info_multas(int&,double&);
    void imprimir(ofstream&) const;
};

ofstream& operator<<(ofstream&,const Flota&);

#endif //HERENCIA_FLOTA_H
