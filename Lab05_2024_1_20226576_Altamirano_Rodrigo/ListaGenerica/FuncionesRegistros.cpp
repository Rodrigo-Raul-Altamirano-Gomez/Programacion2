//
// Created by hrodic on 30/04/2026.
//
#include <cstring>
#include <iomanip>
#include "FuncionesRegistros.h"

bool leeregistro(void*& pedido,ifstream& archPedidos) {
    int codPedido;
    char car;
    if (archPedidos>>codPedido) {
        int *codigoPedido=new int(codPedido),*dni=new int;
        archPedidos>>car>>*dni>>car;
        char* codigoLibro=LeerCadenaExacta(archPedidos);
        pedido=new void*[3]{codigoPedido,dni,codigoLibro};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archPedidos) {
    char *cadenaExacta,buffer[200];
    archPedidos.getline(buffer,200,'\n');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void imprimeregistro(void* pedido,ofstream& archRepPedidos) {
    void** regPedido=(void**)pedido;
    archRepPedidos<<left<<setw(12)<<*(int*)regPedido[0]<<setw(12)<<*(int*)regPedido[1]<<(char*)regPedido[2]<<endl;
}

int cmpregistro(void* pedido1,void* pedido2) {
    if (pedido1 and pedido2) {
        void** regPedido1=(void**)pedido1;
        void** regPedido2=(void**)pedido2;
        int codPedido1=*(int*)regPedido1[0];
        int codPedido2=*(int*)regPedido2[0];
        if (codPedido1<codPedido2) return -1;
        else if (codPedido1==codPedido2) return 0;
        else return  1;
    }
    else if (pedido1 and not pedido2) return -1;
    else return 1;
}
