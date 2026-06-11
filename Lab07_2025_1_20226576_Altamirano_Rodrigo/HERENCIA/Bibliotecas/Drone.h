//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_DRONE_H
#define HERENCIA_DRONE_H

#include "Infraccion.h"

class Drone {
    char* id;
    char* ubicacion;
    int capacidad;
    int cantidad_infracciones;
    Infraccion infracciones[20];
public:
    Drone();
    void set_id(const char*);
    void set_ubicacion(const char*);
    char* get_id() const;
    void insertar_infraccion(const Infraccion&);
    void obtener_multas(int&,double&);
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Drone();
};


#endif //HERENCIA_DRONE_H
