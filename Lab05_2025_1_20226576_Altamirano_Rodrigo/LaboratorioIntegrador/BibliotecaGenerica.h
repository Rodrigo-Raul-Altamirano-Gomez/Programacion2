//
// Created by hrodic on 29/04/2026.
//

#ifndef LABORATORIOINTEGRADOR_BIBLIOTECAGENERICA_H
#define LABORATORIOINTEGRADOR_BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void generaLista(void*&);
void insertaLista(void*,int (*)(void*,void*),void*);
void creaLista(void*,bool (*)(void*&,ifstream&),int (*)(void*,void*),void* (*)(void*,void*),const char*);
void imprimeLista(void*,void (*)(void*,ofstream&),const char*);

#endif //LABORATORIOINTEGRADOR_BIBLIOTECAGENERICA_H
