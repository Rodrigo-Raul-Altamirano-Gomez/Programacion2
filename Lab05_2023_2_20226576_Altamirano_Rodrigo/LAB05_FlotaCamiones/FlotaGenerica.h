//
// Created by hrodic on 30/04/2026.
//

#ifndef LAB05_FLOTACAMIONES_FLOTAGENERICA_H
#define LAB05_FLOTACAMIONES_FLOTAGENERICA_H

#include <fstream>
using namespace std;

void cargacamiones(void*&,int,int,bool (*)(void*&,ifstream&),double (*)(void*),const char*);
int BuscarCamionDisponible(void*,int,int,void*,double (*)(void*));
bool pilavacia(void*);
void push(void*,void*&,double (*)(void*));
void muestracamiones(void*,int,void (*)(void*,ofstream&),const char*);

#endif //LAB05_FLOTACAMIONES_FLOTAGENERICA_H
