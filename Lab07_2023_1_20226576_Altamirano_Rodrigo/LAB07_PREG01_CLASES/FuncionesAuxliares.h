//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB07_PREG01_CLASES_FUNCIONESAUXLIARES_H
#define LAB07_PREG01_CLASES_FUNCIONESAUXLIARES_H

#include <fstream>
#include "Nota.h"
using namespace std;

char* LeerCadenaExacta(ifstream&);
char* CopiarCadenaExacta(const char*);
int ContarCurso(const Nota*,const char*,int&);

#endif //LAB07_PREG01_CLASES_FUNCIONESAUXLIARES_H
