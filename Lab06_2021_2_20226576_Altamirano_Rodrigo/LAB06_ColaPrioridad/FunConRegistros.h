//
// Created by hrodic on 4/05/2026.
//

#ifndef LAB06_COLAPRIORIDAD_FUNCONREGISTROS_H
#define LAB06_COLAPRIORIDAD_FUNCONREGISTROS_H

#include <fstream>
using namespace std;

bool leepedido(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
int prioridadpedido(void*);
void muestrapedido(void*,ofstream&);

#endif //LAB06_COLAPRIORIDAD_FUNCONREGISTROS_H
