//
// Created by hrodic on 30/04/2026.
//

#ifndef LAB05_FLOTACAMIONES_PILACONENTEROS_H
#define LAB05_FLOTACAMIONES_PILACONENTEROS_H

#include <fstream>
using namespace std;

bool leenumero(void*&,ifstream&);
double calculanumero(void*);
int cmpnumero(const void*,const void*);
void imprimenumero(void*,ofstream&);

#endif //LAB05_FLOTACAMIONES_PILACONENTEROS_H
