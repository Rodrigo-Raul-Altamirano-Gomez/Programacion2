//
// Created by hrodic on 1/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2023_2_OPERADORESYFUNCIONES_H
#define FUENTES_BIBLIOTECA_2023_2_OPERADORESYFUNCIONES_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

ifstream& operator>>(ifstream&, Cliente&);
ifstream& operator>>(ifstream&, Producto&);
ifstream& operator>>(ifstream&, Pedido&);
void operator+=(Cliente*, const Pedido&);
int BuscarCliente(Cliente*, int);
bool operator+=(Producto*, Pedido&);
int BuscarProducto(Producto*, const char*);
ofstream& operator<<(ofstream&, const Cliente&);
ofstream& operator<<(ofstream&, const Producto&);
void ImprimirClientes(ofstream&,const int*, int, bool);

#endif //FUENTES_BIBLIOTECA_2023_2_OPERADORESYFUNCIONES_H
