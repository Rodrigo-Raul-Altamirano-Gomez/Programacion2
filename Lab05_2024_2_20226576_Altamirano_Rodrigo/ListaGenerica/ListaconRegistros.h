//
// Created by hrodic on 30/04/2026.
//

#ifndef LISTAGENERICA_LISTACONREGISTROS_H
#define LISTAGENERICA_LISTACONREGISTROS_H

#include <fstream>
using namespace std;

bool leeregistros(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
bool leeordenes(void*&,void*&,ifstream&);
void* compruebaregistro(void*,void*);
void imprimeregistros(void*,ofstream&);

#endif //LISTAGENERICA_LISTACONREGISTROS_H
