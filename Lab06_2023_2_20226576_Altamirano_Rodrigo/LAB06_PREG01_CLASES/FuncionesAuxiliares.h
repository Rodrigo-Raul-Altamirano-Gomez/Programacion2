//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB06_PREG01_CLASES_FUNCIONESAUXILIARES_H
#define LAB06_PREG01_CLASES_FUNCIONESAUXILIARES_H

#include <fstream>
using namespace std;

char* LeerCadenaExacta(ifstream&);
char* CopiarCadenaExacta(const char*);
void ImprimirClientes(const int*,int,const char*,ofstream&);

#endif //LAB06_PREG01_CLASES_FUNCIONESAUXILIARES_H
