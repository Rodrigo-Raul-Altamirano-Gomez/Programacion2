//
// Created by hrodic on 3/05/2026.
//

#ifndef LAB06_TADS_HEROES_ARREGLOS_GENERICOS_H
#define LAB06_TADS_HEROES_ARREGLOS_GENERICOS_H

#include <fstream>
using namespace std;

void llenar_arreglo_heroes(void*&,int&,const char*);
bool leerLineaHeroes(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
int cmp_multicriterio_void(const void*,const void*);

#endif //LAB06_TADS_HEROES_ARREGLOS_GENERICOS_H
