//
// Created by hrodic on 18/04/2026.
//

#ifndef PREGUNTA1_BIB_FUNC_PREG1_H
#define PREGUNTA1_BIB_FUNC_PREG1_H

#include <fstream>
using namespace std;

void leerUsuario(void*&);
bool LeerLineaUsuarios(void*&,ifstream&);
char* LeeCadenaExacta(ifstream&,char);
void imprimirUsuarios(void*);

#endif //PREGUNTA1_BIB_FUNC_PREG1_H
