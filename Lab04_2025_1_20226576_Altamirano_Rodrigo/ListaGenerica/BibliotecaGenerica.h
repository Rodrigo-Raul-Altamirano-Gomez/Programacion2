//
// Created by hrodic on 27/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void creaLista(void*&,bool (*)(void*&,ifstream&),void (*)(void*,void*,void*&,void*&),const char*);
void generaLista(void*&);
void insertaLista(void*,void (*)(void*,void*,void*&,void*&),void*);
void imprimeLista(void*,void (*)(void*,ofstream&),const char*);

#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H
