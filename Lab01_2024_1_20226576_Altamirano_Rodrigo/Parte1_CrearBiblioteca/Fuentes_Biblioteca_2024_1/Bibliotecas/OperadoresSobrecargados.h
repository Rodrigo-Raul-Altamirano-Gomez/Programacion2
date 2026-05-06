//
// Created by hrodic on 9/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_1_OPERADORESSOBRECARGADOS_H
#define FUENTES_BIBLIOTECA_2024_1_OPERADORESSOBRECARGADOS_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

ifstream& operator>> (ifstream&, Libro&);
ifstream& operator>> (ifstream&, Cliente&);
bool operator>> (LibroSolicitado&, Libro*);
int BuscarLibro(const char*,Libro*);
bool operator<< (Cliente&, const LibroSolicitado&);
void operator++ (Cliente&, int);
ofstream& operator<< (ofstream&, const Libro&);
ofstream& operator<< (ofstream&, const Cliente&);
void ImprimirLibrosCliente(ofstream&,const Cliente&,bool);

#endif //FUENTES_BIBLIOTECA_2024_1_OPERADORESSOBRECARGADOS_H
