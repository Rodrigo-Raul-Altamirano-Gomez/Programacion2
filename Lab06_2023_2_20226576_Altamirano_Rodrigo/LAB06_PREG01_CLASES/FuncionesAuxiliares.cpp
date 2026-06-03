//
// Created by hrodic on 7/05/2026.
//
#include <cstring>
#include <iomanip>
#include "FuncionesAuxiliares.h"

char* LeerCadenaExacta(ifstream& archLectura) {
    char *cadenaExacta,buffer[200];
    archLectura.getline(buffer,200,',');
    if (not archLectura) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

char* CopiarCadenaExacta(const char* cadena) {
    char* cadenaExacta=new char[strlen(cadena)+1];
    strcpy(cadenaExacta,cadena);
    return cadenaExacta;
}

void ImprimirClientes(const int* clientes,int cantClientes,const char* salidaError,ofstream& archReporte) {
    if (cantClientes>0) {
        for (int i=0;i<cantClientes;i++) {
            archReporte<<setw(8)<<clientes[i]<<setw(3)<<" ";
        }
    }
    else archReporte<<salidaError;
}