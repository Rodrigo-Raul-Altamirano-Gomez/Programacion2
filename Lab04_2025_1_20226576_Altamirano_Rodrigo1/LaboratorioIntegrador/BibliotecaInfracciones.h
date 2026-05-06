//
// Created by hrodic on 29/04/2026.
//

#ifndef LABORATORIOINTEGRADOR_BIBLIOTECAINFRACCIONES_H
#define LABORATORIOINTEGRADOR_BIBLIOTECAINFRACCIONES_H

#include <fstream>
using namespace std;

bool leeinfracciones(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
int cmpinfracciones(void*,void*);
void* buscalistainfraccion(void*,void*);

#endif //LABORATORIOINTEGRADOR_BIBLIOTECAINFRACCIONES_H
