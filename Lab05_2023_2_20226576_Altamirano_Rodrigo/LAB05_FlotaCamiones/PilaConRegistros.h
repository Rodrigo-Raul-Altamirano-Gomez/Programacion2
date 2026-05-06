//
// Created by hrodic on 30/04/2026.
//

#ifndef LAB05_FLOTACAMIONES_PILACONREGISTROS_H
#define LAB05_FLOTACAMIONES_PILACONREGISTROS_H

#include <fstream>
using namespace std;

bool leeregistro(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
double calcularegistro(void*);
int cmpregistro(const void*,const void*);
void imprimeregistro(void*,ofstream&);

#endif //LAB05_FLOTACAMIONES_PILACONREGISTROS_H
