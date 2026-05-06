//
// Created by hrodic on 5/04/2026.
//

#ifndef BIBESTATICAENUNAAPLICACION_FUNCIONES_H
#define BIBESTATICAENUNAAPLICACION_FUNCIONES_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

void CargarArrClientes(Cliente*);
void CargarArrProductos(Producto*);
void ProcesarPedidos(Cliente*,Producto*);
void EmitirReporte(Cliente*,Producto*);
void ImprimirProductos(Producto*,ofstream&);
void ImprimirClientesServidosONoServidos(ofstream&,const int*, int, bool);

#endif //BIBESTATICAENUNAAPLICACION_FUNCIONES_H
