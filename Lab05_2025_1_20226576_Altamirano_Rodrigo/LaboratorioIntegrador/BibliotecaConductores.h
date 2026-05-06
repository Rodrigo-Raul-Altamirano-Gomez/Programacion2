//
// Created by hrodic on 29/04/2026.
//

#ifndef LABORATORIOINTEGRADOR_BIBLIOTECACONDUCTORES_H
#define LABORATORIOINTEGRADOR_BIBLIOTECACONDUCTORES_H

#include <fstream>
using namespace std;

bool leeconductores(void*&,ifstream&);
char* LeerCadenaExacta1(ifstream&);
int cmpconductores(void*,void*);
void* buscalistaconductores(void*,void*);
void cargaUnidades(void*,const char*);
bool leerLineaUnidades(int&,void*&,ifstream&);
void InsertarPlacaAlConductor(void*,void*&);
void imprimeconductores(void*,ofstream&);

#endif //LABORATORIOINTEGRADOR_BIBLIOTECACONDUCTORES_H
