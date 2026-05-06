//
// Created by hrodic on 26/04/2026.
//

#ifndef COLALABORATORIO0102_FUNCIONESLABORATORIO02_H
#define COLALABORATORIO0102_FUNCIONESLABORATORIO02_H

#include <fstream>
using namespace std;

bool leerCliente(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
void imprimirCliente(void*,ofstream&);
void atiendeCola(void*,double);
void ImprimirHora(int,ofstream&);
void AtenderClientes(void*,double,ofstream&,double&);
void ImprimirCliente(void*,double,double,double,ofstream&);

#endif //COLALABORATORIO0102_FUNCIONESLABORATORIO02_H
