//
// Created by hrodic on 30/04/2026.
//

#include "FuncionesEnteras.h"

bool leenum(void*& numero,ifstream& archNumeros) {
    int num;
    if (archNumeros>>num) {
        numero=new int(num);
        return true;
    }
    return false;
}

void imprimenum(void* numero,ofstream& archRepNumeros) {
    archRepNumeros<<*(int*)numero<<endl;
}

int cmpnum(void* numero1,void* numero2) {
    int *num1=(int*)numero1,*num2=(int*)numero2;
    if (num1 and num2) {
        if (*num1<*num2) return -1;
        else if (*num1==*num2) return 0;
        else return  1;
    }
    else if (numero1 and not numero2) return -1;
    else return 1;
}
