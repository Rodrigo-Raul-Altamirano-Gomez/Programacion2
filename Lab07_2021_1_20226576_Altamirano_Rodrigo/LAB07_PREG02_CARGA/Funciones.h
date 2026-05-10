//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB07_PREG02_CARGA_FUNCIONES_H
#define LAB07_PREG02_CARGA_FUNCIONES_H

#include "Conductor.h"

void cargarConductores(Conductor*&,int&);
void procesarFaltas(Conductor*,int);
void completarInfracciones(Conductor*,int);
void calcularTotales(Conductor*,int);
void emitirReporte(const Conductor*,int,const char*);
void aplicarAmnistia(Conductor*,int);

#endif //LAB07_PREG02_CARGA_FUNCIONES_H
