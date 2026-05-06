//
// Created by hrodic on 30/04/2026.
//

#ifndef LISTAGENERICA_LISTACONENTEROS_H
#define LISTAGENERICA_LISTACONENTEROS_H

#include <fstream>
using namespace std;

bool leenumeros(void*&,ifstream&);
bool leeregnumeros(void*&,void*&,ifstream&);
void* compruebanumero(void*,void*);
void imprimenumeros(void*,ofstream&);

#endif //LISTAGENERICA_LISTACONENTEROS_H
