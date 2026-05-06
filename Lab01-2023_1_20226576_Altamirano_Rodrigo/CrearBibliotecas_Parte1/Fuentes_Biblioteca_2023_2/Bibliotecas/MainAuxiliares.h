//
// Created by hrodic on 3/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2023_2_MAINAUXILIARES_H
#define FUENTES_BIBLIOTECA_2023_2_MAINAUXILIARES_H

#include "Estructuras.h"
#include <fstream>
using namespace std;

void AbrirArchivos(ifstream&, ifstream&, ifstream&, ofstream&);
void ProbarSobrecargas(ifstream&, ifstream&, ifstream&, ofstream&);
void CargarArreglos(ifstream&,ifstream&,ifstream&,Cliente*,Producto*,Pedido*);
void ImprimirPrueba(ofstream&,const Cliente&,const Producto&,const Pedido&);

#endif //FUENTES_BIBLIOTECA_2023_2_MAINAUXILIARES_H
