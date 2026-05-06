//
// Created by hrodic on 3/05/2026.
//

#ifndef LAB06_TRASLADAPILA_BIBLIOTECAPILAGENERICA_H
#define LAB06_TRASLADAPILA_BIBLIOTECAPILAGENERICA_H

#include <fstream>
using namespace std;

void cargaarreglo(void*&,int (*)(const void*,const void*),bool (*)(void*&,ifstream&),const char*);
void cargapila(void*&,void*);
bool pilavacia(void*);
void push(void*,void*&);
void muevepila(void*,void*&);
void Hanoi(int,void*,void*,void*);
void* pop(void*);
void imprimepila(void*,void (*)(void*,ofstream&),const char*);

#endif //LAB06_TRASLADAPILA_BIBLIOTECAPILAGENERICA_H
