//
// Created by hrodic on 30/04/2026.
//

#ifndef LISTAGENERICA_FUNCIONESREGISTROS_H
#define LISTAGENERICA_FUNCIONESREGISTROS_H

#include <fstream>
using namespace std;

bool leeregistro(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
void imprimeregistro(void*,ofstream&);
int cmpregistro(void*,void*);

#endif //LISTAGENERICA_FUNCIONESREGISTROS_H
