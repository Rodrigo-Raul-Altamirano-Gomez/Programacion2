//
// Created by hrodic on 30/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H

#include <fstream>
using namespace std;

void crealista(void*&,bool (*)(void*&,ifstream&),const char*);
void insertalista(void*,void*);
bool listavacia(void*);
void imprimelista(void*,void (*)(void*,ofstream&),const char*);
void* quitalista(void*);
void combinalista(void*,void*,void*&,int (*)(void*,void*));

#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H
