//
// Created by hrodic on 4/06/2026.
//

#ifndef PREG01_COMANDA_H
#define PREG01_COMANDA_H

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"
#include <fstream>
using namespace std;

class Comanda {
    int id;
    Bebida bebidas[20];
    Entrada entradas[20];
    PlatoFondo platos_fondo[20];
    int cantidad_bebidas;
    int cantidad_entradas;
    int cantidad_platos_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    char* estado;
public:
    Comanda();
    void set_id(int);
    int get_id() const;
    void completar(int,int);
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Comanda();
};

ifstream& operator>>(ifstream&,Comanda&);
ofstream& operator<<(ofstream&,const Comanda&);

#endif //PREG01_COMANDA_H
