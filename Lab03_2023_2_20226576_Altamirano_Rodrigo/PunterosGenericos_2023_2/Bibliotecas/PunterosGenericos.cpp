//
// Created by hrodic on 21/04/2026.
//
#include <cstring>
#include "PunterosGenericos.h"

void cargaproductos(void*& productos) {
    ifstream archProductos("Productos2.csv",ios::in);
    void *bufferProductos[180],*producto,**regProductos;
    int cantProductos=0;
    while (LeerLineaProductos(producto,archProductos)) {
        bufferProductos[cantProductos]=producto;
        cantProductos++;
    }
    productos=new void*[cantProductos+1]{};
    regProductos=(void**)productos;
    for (int i=0;i<cantProductos;i++) regProductos[i]=bufferProductos[i];
}

bool LeerLineaProductos(void*& producto,ifstream& archProductos) {
    char *codProducto,*descripcionProducto,*tipoProducto,car;
    double* precioProducto;
    codProducto=LeerCadenaExacta(archProductos,',');
    if (codProducto) {
        precioProducto=new double;
        tipoProducto=new char;
        descripcionProducto=LeerCadenaExacta(archProductos,',');
        archProductos>>*precioProducto>>car>>*tipoProducto;
        archProductos.ignore();
        producto=new void*[4]{codProducto,descripcionProducto,precioProducto,tipoProducto};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archLectura,char delim) {
    char *cadenaExacta,buffer[200];
    archLectura.getline(buffer,200,delim);
    if (archLectura.eof()) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void cargaclientes(void*& clientes) {
    ifstream archClientes("Clientes2.csv",ios::in);
    int cantClientes=0;
    void *bufferClientes[150],*cliente,**regClientes;
    while (LeerLineaClientes(cliente,archClientes)) {
        bufferClientes[cantClientes]=cliente;
        cantClientes++;
    }
    clientes=new void*[cantClientes+1]{};
    regClientes=(void**)clientes;
    for (int i=0;i<cantClientes;i++) regClientes[i]=bufferClientes[i];
}

bool LeerLineaClientes(void*& cliente,ifstream& archClientes) {
    int *dniCliente,dni;
    char* nombreCliente;
    double* lineaCredito;
    if (archClientes>>dni) {
        dniCliente=new int(dni);
        lineaCredito=new double();
        archClientes.ignore();
        nombreCliente=LeerCadenaExacta(archClientes,',');
        archClientes.ignore(50,',');
        archClientes>>*lineaCredito;
        cliente=new void*[4]{dniCliente,nombreCliente,nullptr,lineaCredito};
        return true;
    }
    return false;
}

void cargapedidos(void* productos,void* clientes) {
    ifstream archPedidos("Pedidos2.csv",ios::in);
    void *pedido,**regPedido,**regCliente,**regProducto;
    int dniCliente;
    double *totalPedido,*lineaCreditoCliente;
    while (LeerLienaPedidos(dniCliente,pedido,archPedidos)) {
        regPedido=(void**)pedido;
        regCliente=BuscarCliente(dniCliente,clientes);
        regProducto=BuscarProducto((char*)(regPedido[0]),productos);
        if (regCliente and regProducto) {
            totalPedido=new double((*(double*)(regProducto[2]))*(*(int*)(regPedido[1])));
            regPedido[2]=totalPedido;
            if (*(char*)(regProducto[3])=='S') {
                lineaCreditoCliente=(double*)(regCliente[3]);
                if (*lineaCreditoCliente-*totalPedido>=0) {
                    AñadirPedidoAlCliente(pedido,regCliente[2]);
                    *lineaCreditoCliente-=*totalPedido;
                }
                else DeletearPedido(regPedido);
            }
            else AñadirPedidoAlCliente(pedido,regCliente[2]);
        }
        else DeletearPedido(regPedido);
    }
}

bool LeerLienaPedidos(int& dniCliente,void*& pedido,ifstream& archPedidos) {
    char *codProducto,car;
    int* cantProducto;
    codProducto=LeerCadenaExacta(archPedidos,',');
    if (codProducto) {
        cantProducto=new int;
        archPedidos>>dniCliente>>car>>*cantProducto;
        archPedidos.ignore();
        pedido=new void*[3]{codProducto,cantProducto,nullptr};
        return true;
    }
    return false;
}

void** BuscarCliente(int dniCliente,void* clientes) {
    void **regCliente,**regClientes=(void**)clientes;
    for (int i=0;regClientes[i];i++) {
        regCliente=(void**)(regClientes[i]);
        if (dniCliente==*(int*)(regCliente[0])) return regCliente;
    }
    return nullptr;
}

void DeletearPedido(void** regPedido) {
    delete[] (char*)(regPedido[0]);
    delete[] (int*)(regPedido[1]);
    if (regPedido[2]) delete[] (double*)(regPedido[2]);
    delete[] regPedido;
}

void** BuscarProducto(const char* codProducto,void* productos) {
    void **regProducto,**regProductos=(void**)productos;
    for (int i=0;regProductos[i];i++) {
        regProducto=(void**)(regProductos[i]);
        if (strcmp(codProducto,(char*)(regProducto[0]))==0) return regProducto;
    }
    return nullptr;
}

void AñadirPedidoAlCliente(void* pedido,void*& pedidosCliente) {
    int cantPedidos=0;
    void **regPedidosCliente,**aux;
    if (not pedidosCliente) pedidosCliente=new void*[2]{pedido,nullptr};
    else {
        regPedidosCliente=(void**)pedidosCliente;
        for (int i=0;regPedidosCliente[i];i++) cantPedidos++;
        aux=new void*[cantPedidos+2]{};
        for (int i=0;i<cantPedidos;i++) aux[i]=regPedidosCliente[i];
        aux[cantPedidos]=pedido;
        delete[] regPedidosCliente;
        pedidosCliente=aux;
    }
}