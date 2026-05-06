//
// Created by hrodic on 3/05/2026.
//
#include <cstring>
#include <iomanip>
#include "PilaConRegistros.h"

bool leeregistro(void*& medicina,ifstream& archMedicinas) {
    int codigo;
    if (archMedicinas>>codigo) {
        int* codigoMedicamento=new int(codigo);
        double* pesoCaja=new double;
        archMedicinas.ignore();
        char* descripcionMedicamento=LeerCadenaExacta(archMedicinas);
        archMedicinas>>*pesoCaja;
        medicina=new void*[3]{codigoMedicamento,descripcionMedicamento,pesoCaja};
        return true;
    }

    return false;
}

char* LeerCadenaExacta(ifstream& archMedicinas) {
    char *cadenaExacta,buffer[200];
    archMedicinas.getline(buffer,200,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

int cmpregistro(const void* a,const void* b) {
    const void* medicamentoA=*(const void**)a;
    const void* medicamentoB=*(const void**)b;
    const void** regMedicamentoA=(const void**)medicamentoA;
    const void** regMedicamentoB=(const void**)medicamentoB;
    const double pesoMedicamentoA=*(const double*)regMedicamentoA[2];
    const double pesoMedicamentoB=*(const double*)regMedicamentoB[2];
    return pesoMedicamentoB-pesoMedicamentoA;
}

void imprimeregistro(void* medicamento,ofstream& archRepMedicamentos) {
    void** regMedicamentos=(void**)medicamento;
    archRepMedicamentos<<left<<setw(8)<<*(int*)regMedicamentos[0]<<setw(40)<<(char*)regMedicamentos[1];
    archRepMedicamentos<<right<<setw(5)<<*(double*)regMedicamentos[2]<<endl;
}