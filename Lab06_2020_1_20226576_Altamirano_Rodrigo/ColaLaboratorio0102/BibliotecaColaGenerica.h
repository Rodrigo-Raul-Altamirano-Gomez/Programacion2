//
// Created by hrodic on 26/04/2026.
//

#ifndef COLALABORATORIO0102_BIBLIOTECACOLAGENERICA_H
#define COLALABORATORIO0102_BIBLIOTECACOLAGENERICA_H

#include <fstream>
using namespace std;

void creaCola(void*&,bool (*)(void*&,ifstream&),const char*);
bool colaVacia(void*);
void encola(void*,void*);
void imprimir(void*,void (*)(void*,ofstream&),const char*);
void* desencola(void*);

#endif //COLALABORATORIO0102_BIBLIOTECACOLAGENERICA_H
