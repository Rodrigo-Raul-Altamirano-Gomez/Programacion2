//
// Created by hrodic on 27/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAREGISTROS_H
#define LISTAGENERICA_BIBLIOTECAREGISTROS_H

#include <fstream>
using namespace std;

bool leeregistro(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
void clasificaregistro(void*,void*,void*&,void*&);
void imprimeregistro(void*,ofstream&);

#endif //LISTAGENERICA_BIBLIOTECAREGISTROS_H
