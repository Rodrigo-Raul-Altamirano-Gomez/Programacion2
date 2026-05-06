//
// Created by hrodic on 3/05/2026.
//

#include "PilaConEnteros.h"

bool leenumero(void*& numero,ifstream& archNumeros) {
    int num;
    if (archNumeros>>num) {
        numero=new int(num);
        return true;
    }
    return false;
}

int cmpnumero(const void* a,const void* b) {
    const void* numeroA=*(const void**)a;
    const void* numeroB=*(const void**)b;
    int numA=*(int*)numeroA;
    int numB=*(int*)numeroB;
    return numB-numA;
}

void imprimenumero(void* numero,ofstream& archRepnumeros) {
    int num=*(int*)numero;
    archRepnumeros<<num<<endl;
}