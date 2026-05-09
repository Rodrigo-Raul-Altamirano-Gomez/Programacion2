//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG02_CARGA_FUNCIONES_H
#define LAB07_PREG02_CARGA_FUNCIONES_H

#include "Cliente.h"

void cargarClientes(Cliente*);
void cargarPedidos(Pedido*);
void agregarPedidos(Cliente*,const Pedido*);
void eliminarPedidos(Cliente*);
void aplicarDescuentos(Cliente*);
void emitirReporte(const Cliente*);

#endif //LAB07_PREG02_CARGA_FUNCIONES_H
