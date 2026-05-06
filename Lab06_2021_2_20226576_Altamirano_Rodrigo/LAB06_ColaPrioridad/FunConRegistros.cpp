//
// Created by hrodic on 4/05/2026.
//
#include <cstring>
#include <iomanip>
#include "FunConRegistros.h"

bool leepedido(void*& pedido,ifstream& archPedidos) {
    int cod;
    char car;
    if (archPedidos>>cod) {
        int* codigo=new int(cod);
        char* tipo=new char();
        archPedidos>>*tipo>>car;
        char* codLibro=LeerCadenaExacta(archPedidos,',');
        char* nombre=LeerCadenaExacta(archPedidos,'\n');
        pedido=new void*[4]{codigo,tipo,codLibro,nombre};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archPedidos,char delim) {
    char *cadenaExacta,buffer[200];
    archPedidos.getline(buffer,200,delim);
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

int prioridadpedido(void* pedido) {
    void** regPedido=(void**)pedido;
    char tipo=*(char*)regPedido[1];
    if (tipo=='D') return 1;
    else if (tipo=='E') return 2;
    else return 3;
}

void muestrapedido(void* pedido,ofstream& archRepPedidos) {
    void** regPedidos=(void**)pedido;
    archRepPedidos<<left<<setw(5)<<*(char*)regPedidos[1]<<setw(12)<<*(int*)regPedidos[0];
    archRepPedidos<<setw(40)<<(char*)regPedidos[3]<<(char*)regPedidos[2]<<endl;
}