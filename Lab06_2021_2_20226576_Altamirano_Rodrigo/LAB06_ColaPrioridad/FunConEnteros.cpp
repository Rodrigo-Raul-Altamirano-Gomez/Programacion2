//
// Created by hrodic on 4/05/2026.
//
#include <iomanip>
#include "FunConEnteros.h"

bool leenumero(void*& numero,ifstream& archNumeros) {
    int num;
    if (archNumeros>>num) {
        numero=new int(num);
        return true;
    }
    return false;
}

int prioridadnumero(void* numero) {
    int num=*(int*)numero;
    if (num<50) return 3;
    else if (num>=50 and num<=100) return 2;
    else return 1;
}

void muestranumero(void* numero,ofstream& archReporteNumeros) {
    int num=*(int*)numero;
    archReporteNumeros<<setw(4)<<num<<endl;
}