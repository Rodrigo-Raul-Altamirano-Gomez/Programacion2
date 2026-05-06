//
// Created by hrodic on 21/04/2026.
//
#include <cstring>
#include <iomanip>
#include "PunterosGenericos.h"

void cargaclientes(void*& clientes) {
    ifstream archClientes("Clientes.csv",ios::in);
    void *bufferClientes[75],*cliente;
    int cantClientes=0;
    while (LeerLineaClientes(cliente,archClientes)) {
        bufferClientes[cantClientes]=cliente;
        cantClientes++;
    }
    clientes=new void*[cantClientes+1]{};
    void** regClientes=(void**)clientes;
    for (int i=0;i<cantClientes;i++) regClientes[i]=bufferClientes[i];
}

bool LeerLineaClientes(void*& cliente,ifstream& archClientes) {
    int dni;
    char* nombreCliente;
    if (archClientes>>dni) {
        int* dniCliente=new int(dni);
        archClientes.ignore();
        nombreCliente=LeeCadenaExacta(archClientes,'\n');
        cliente=new void*[2]{dniCliente,nombreCliente};
        return true;
    }
    return false;
}

char* LeeCadenaExacta(ifstream& archClientes,char delim) {
    char *cadenaExacta,buffer[200];
    archClientes.getline(buffer,200,delim);
    if (archClientes.eof()) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void creareserva(void*& reserva) {
    ifstream archLibros("Libros.csv",ios::in);
    void *bufferLibros[275],*libro;
    int cantLibros=0;
    while (LeerLineaLibros(libro,archLibros)) {
        bufferLibros[cantLibros]=libro;
        cantLibros++;
    }
    reserva=new void*[cantLibros+1]{};
    void** regLibros=(void**)reserva;
    for (int i=0;i<cantLibros;i++) regLibros[i]=bufferLibros[i];
}

bool LeerLineaLibros(void*& libro,ifstream& archLibros) {
    char* codLibro;
    codLibro=LeeCadenaExacta(archLibros,',');
    if (codLibro) {
        int* stockLibro=new int;
        char* tituloLibro=LeeCadenaExacta(archLibros,',');
        char* autorLibro=LeeCadenaExacta(archLibros,',');
        archLibros>>*stockLibro;
        archLibros.ignore(50,'\n');
        void** pedidosClientes=new void*[*stockLibro+1]{};
        libro=new void*[5]{codLibro,tituloLibro,autorLibro,pedidosClientes,stockLibro};
        return true;
    }
    delete[] codLibro;
    return false;
}

void cargareservar(void* clientes,void* reserva) {
    ifstream arrchPedidos("Pedidos2.csv",ios::in);
    char codLibro[8];
    int dniCliente;
    while (LeerLineaPedidos(dniCliente,codLibro,arrchPedidos)) {
        void** regLibro=(void**)BuscarLibro(codLibro,reserva);
        char* nombreCliente=BuscarCliente(dniCliente,clientes);
        if (nombreCliente and regLibro) {
            int* stockLibro=(int*)(regLibro[4]);
            if (*stockLibro>0) {
                AñadirPedidoAlLibro(dniCliente,nombreCliente,regLibro[3]);
                (*stockLibro)--;
            }
        }
    }
}

bool LeerLineaPedidos(int& dniCliente,char* codLibro,ifstream& arrchPedidos) {
    if (arrchPedidos>>dniCliente) {
        arrchPedidos.ignore();
        arrchPedidos.getline(codLibro,8,'\n');
        return true;
    }
    return false;
}

char* BuscarCliente(int dniCliente,void* clientes) {
    void** regClientes=(void**)clientes;
    for (int i=0;regClientes[i];i++) {
        void** regCliente=(void**)(regClientes[i]);
        if (dniCliente==*(int*)(regCliente[0])) return (char*)(regCliente[1]);
    }
    return nullptr;
}

void* BuscarLibro(const char* codLibro,void* reserva) {
    void** regLibros=(void**)reserva;
    for (int i=0;regLibros[i];i++) {
        void** regLibro=(void**)(regLibros[i]);
        if (strcmp(codLibro,(char*)(regLibro[0]))==0) return regLibro;
    }
    return nullptr;
}

void AñadirPedidoAlLibro(int dniCliente,const char* nombreCliente,void* pedidosLibro) {
    int *ptrDniCliente=new int(dniCliente),cantPedidosLibro=0;
    char* ptrNombreCliente=new char[strlen(nombreCliente)+1];
    strcpy(ptrNombreCliente,nombreCliente);
    void **regPedidosLibro=(void**)pedidosLibro,**pedidoLibro=new void*[2]{ptrDniCliente,ptrNombreCliente};
    for (int i=0;regPedidosLibro[i];i++) cantPedidosLibro++;
    regPedidosLibro[cantPedidosLibro]=pedidoLibro;
}

void reportefinal(void* reserva) {
    ofstream archReporte("Reporte.txt",ios::out);
    void** regLibros=(void**)reserva;
    archReporte<<"Reporte de libros reservados"<<endl;
    archReporte<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl;
    for (int i=0;regLibros[i];i++) {
        void **regLibro=(void**)(regLibros[i]);
        archReporte<<"Libro: "<<(char*)(regLibro[0])<<endl;
        archReporte<<"Nombre del libro: "<<(char*)(regLibro[1])<<endl;
        archReporte<<"Autor: "<<(char*)(regLibro[2])<<endl;
        archReporte<<left<<setw(12)<<"DNI"<<"Nombre del solicitante"<<endl;
        archReporte<<setfill('-')<<setw(60)<<" "<<setfill(' ')<<endl;
        void** regPedidosLibro=(void**)(regLibro[3]);
        for (int j=0;regPedidosLibro[j];j++) {
            void** regPedidoLibro=(void**)(regPedidosLibro[j]);
            archReporte<<setw(12)<<*(int*)(regPedidoLibro[0]);
            archReporte<<(char*)(regPedidoLibro[1])<<endl;
        }
    }
}