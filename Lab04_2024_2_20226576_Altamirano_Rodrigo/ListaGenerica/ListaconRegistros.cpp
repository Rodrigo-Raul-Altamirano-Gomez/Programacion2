//
// Created by hrodic on 30/04/2026.
//
#include <cstring>
#include <iomanip>
#include "ListaconRegistros.h"

bool leeregistros(void*& repartidor,ifstream& archRepartidores) {
    char* codigoRepartidor=LeerCadenaExacta(archRepartidores,',');
    if (codigoRepartidor) {
        char* nombreRepartidor=LeerCadenaExacta(archRepartidores,',');
        char* unidadRepartidor=LeerCadenaExacta(archRepartidores,'\n');
        repartidor=new void*[3]{codigoRepartidor,nombreRepartidor,unidadRepartidor};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archRepartidores,char delim) {
    char *cadenaExacta,buffer[200];
    archRepartidores.getline(buffer,200,delim);
    if (not archRepartidores) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

bool leeordenes(void*& claveRepartidor,void*& ordenRepartidor,ifstream& archOrdenes) {
    int dni;
    char car;
    if (archOrdenes>>dni) {
        int *dniCliente=new int(dni),*cantidadOrden=new int();
        archOrdenes>>car>>*cantidadOrden>>car;
        char* codigoPlato=LeerCadenaExacta(archOrdenes,',');
        char* codigoRepartidor=LeerCadenaExacta(archOrdenes,'\n');
        claveRepartidor=new void*[3]{codigoRepartidor};
        ordenRepartidor=new void*[3]{dniCliente,cantidadOrden,codigoPlato};
        return true;
    }
    return false;
}

void* compruebaregistro(void* claveRepartidor,void* listaRepartidores) {
    void** regListaRepartidores=(void**)listaRepartidores;
    void** regNodoActual=(void**)regListaRepartidores[0];
    void** regRepartidorClave=(void**)claveRepartidor;
    for (int i=0;i<*(int*)regListaRepartidores[2];i++) {
        void** regDuplaActual=(void**)regNodoActual[0];
        void** regRepartidor=(void**)regDuplaActual[0];
        if (strcmp((char*)regRepartidor[0],(char*)regRepartidorClave[0])==0) return regDuplaActual[1];
        regNodoActual=(void**)regNodoActual[1];
    }
    return nullptr;
}

void imprimeregistros(void* duplaRepartidor,ofstream& archRepRepartidores) {
    void** regDuplaRepartidor=(void**)duplaRepartidor;
    void** regRepartidor=(void**)regDuplaRepartidor[0];
    archRepRepartidores<<left<<setw(12)<<(char*)regRepartidor[0]<<(char*)regRepartidor[1]<<endl;
    archRepRepartidores<<"Ordenes:"<<endl;
    void** regOrdenesRepartidor=(void**)regDuplaRepartidor[1];
    for (int i=0;regOrdenesRepartidor[i];i++) {
        void** regOrdenRepartidor=(void**)regOrdenesRepartidor[i];
        archRepRepartidores<<setw(12)<<*(int*)regOrdenRepartidor[0]<<setw(10)<<*(int*)regOrdenRepartidor[1];
        archRepRepartidores<<(char*)regOrdenRepartidor[2]<<endl;
    }
}