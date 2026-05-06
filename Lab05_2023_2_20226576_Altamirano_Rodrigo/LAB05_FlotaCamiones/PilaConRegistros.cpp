//
// Created by hrodic on 30/04/2026.
//
#include <cstring>
#include <iomanip>
#include "PilaConRegistros.h"

bool leeregistro(void*& pedido,ifstream& archPedidos) {
    char* codProducto=LeerCadenaExacta(archPedidos);
    if (codProducto) {
        int* cantProducto=new int;
        double* pesoPedido=new double;
        char car;
        archPedidos.ignore(20,',');
        archPedidos>>*cantProducto>>car>>*pesoPedido;
        archPedidos.ignore();
        pedido=new void*[3]{codProducto,cantProducto,pesoPedido};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archPedidos) {
    char *cadenaExacta,buffer[200];
    archPedidos.getline(buffer,200,',');
    if (not archPedidos) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

double calcularegistro(void* pedido) {
    void** regPedido=(void**)pedido;
    double pesoPedido=*(double*)regPedido[2];
    return pesoPedido;
}

int cmpregistro(const void* a,const void* b) {
    const void* flotaA=*(const void**)a;
    const void* flotaB=*(const void**)b;
    const void** regNodoPrincipalA=(const void**)flotaA;
    const void** regNodoPrincipalB=(const void**)flotaB;
    double pesoFlotaA=*(double*)regNodoPrincipalA[1];
    double pesoFlotaB=*(double*)regNodoPrincipalB[1];
    return pesoFlotaA-pesoFlotaB;
}

void imprimeregistro(void* pedido,ofstream& archReportePedidos) {
    void** regPedido=(void**)pedido;
    char* codProducto=(char*)regPedido[0];
    int cantProducto=*(int*)regPedido[1];
    double pesoPedido=*(double*)regPedido[2];
    archReportePedidos<<setw(10)<<" "<<left<<setw(10)<<codProducto<<right<<setw(3)<<cantProducto;
    archReportePedidos<<setw(8)<<pesoPedido<<endl;
}