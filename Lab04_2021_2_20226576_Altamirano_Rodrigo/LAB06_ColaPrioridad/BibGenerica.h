//
// Created by hrodic on 4/05/2026.
//

#ifndef LAB06_COLAPRIORIDAD_BIBGENERICA_H
#define LAB06_COLAPRIORIDAD_BIBGENERICA_H

#include <fstream>
using namespace std;

void creacola(void*&,bool (*)(void*&,ifstream&),int (*)(void*),const char*);
void encola(void*,int,void*&);
bool colavacia(void*);
void ColocarNodoPrioridadAnterior(void*,int,void*&);
void descargarcola(void*,void (*)(void*,ofstream&),const char*);
void* desencola(void*&);

#endif //LAB06_COLAPRIORIDAD_BIBGENERICA_H
