//
// Created by hrodic on 26/04/2026.
//

#include "FuncionesLaboratorio01.h"

#include "BibliotecaColaGenerica.h"

bool leenumero(void*& numero,ifstream& archNumeros) {
    int num;
    if (archNumeros>>num) {
        numero=new int(num);
        return true;
    }
    return false;
}

void imprimenumero(void* numero,ofstream& archNumeros) {
    archNumeros<<*(int*)numero<<endl;
}

void atiendeNumero(void* cola) {
    while (not colaVacia(cola)) {
        int* numero=(int*)desencola(cola);
        delete numero;
    }
}