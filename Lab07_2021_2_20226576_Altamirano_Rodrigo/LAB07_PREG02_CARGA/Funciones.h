//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB07_PREG02_CARGA_FUNCIONES_H
#define LAB07_PREG02_CARGA_FUNCIONES_H

#include "Libro.h"
#include "Usuario.h"

void cargarUsuarios(Usuario*&);
void cargarLibros(Libro*&);
void procesarPrestamos(Usuario*,Libro*);
void determinarDeudas(Usuario*);
void emitirReporteUsuarios(const Usuario*);
void emitirReporteLibros(const Libro*);

#endif //LAB07_PREG02_CARGA_FUNCIONES_H
