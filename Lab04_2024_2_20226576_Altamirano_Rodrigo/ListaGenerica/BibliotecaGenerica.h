//
// Created by hrodic on 30/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void crealista(void*&,bool (*)(void*&,ifstream&),const char*);
void construir(void*&);
void insertafinal(void*,void*);
bool eslistavacia(void* lista);
void cargalista(void*,void* (*)(void*,void*),bool (*)(void*&,void*&,ifstream&),const char*);
void muestralista(void*,void (*)(void*,ofstream&),const char*);

#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H
