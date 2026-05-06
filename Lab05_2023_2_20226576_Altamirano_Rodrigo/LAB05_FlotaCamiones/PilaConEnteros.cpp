//
// Created by hrodic on 30/04/2026.
//

#include "PilaConEnteros.h"

bool leenumero(void*& numero,ifstream& archNumeros) {
    double num;
    if (archNumeros>>num) {
        numero=new double(num);
        return true;
    }
    return false;
}

double calculanumero(void* numero) {
    return *(double*)numero;
}

int cmpnumero(const void* ptrPilaNumeros1,const void* ptrPilaNumeros2) {
    const void* pilaNumeros1=*(const void**)ptrPilaNumeros1;
    const void* pilaNumeros2=*(const void**)ptrPilaNumeros2;
    const void** regNodoPrincipal1=(const void**)pilaNumeros1;
    const void** regNodoPrincipal2=(const void**)pilaNumeros2;
    return *(const double*)regNodoPrincipal2[1]-*(const double*)regNodoPrincipal1[1];
}

void imprimenumero(void* numero,ofstream& archRepNumeros) {
    archRepNumeros<<*(double*)numero<<endl;
}