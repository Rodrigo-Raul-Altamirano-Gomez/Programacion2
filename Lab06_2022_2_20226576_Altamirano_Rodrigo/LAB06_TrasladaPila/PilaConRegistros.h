//
// Created by hrodic on 3/05/2026.
//

#ifndef LAB06_TRASLADAPILA_PILACONREGISTROS_H
#define LAB06_TRASLADAPILA_PILACONREGISTROS_H

#include <fstream>
using namespace std;

bool leeregistro(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
int cmpregistro(const void*,const void*);
void imprimeregistro(void*,ofstream&);

#endif //LAB06_TRASLADAPILA_PILACONREGISTROS_H
