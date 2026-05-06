//
// Created by hrodic on 21/04/2026.
//
#include <iomanip>
#include "MuestraPunteros.h"

void imprimeproductos(void* productos) {
    void **regProducto,**regProductos=(void**)productos;
    ofstream archReporteProductos("ReporteProductos.txt",ios::out);
    archReporteProductos<<fixed<<setprecision(2)<<"PRODUCTOS"<<endl;
    archReporteProductos<<left<<setw(12)<<"CODIGO"<<setw(51)<<"DESCRIPCION"<<setw(10)<<"PRECIO"<<"TIPO"<<endl;
    for (int i=0;regProductos[i];i++) {
        regProducto=(void**)(regProductos[i]);
        archReporteProductos<<left<<setw(12)<<(char*)(regProducto[0])<<setw(50)<<(char*)(regProducto[1]);
        archReporteProductos<<right<<setw(7)<<*(double*)(regProducto[2])<<setw(7)<<*(char*)(regProducto[3])<<endl;
    }
}

void imprimeclientes(void* clientes) {
    void **regCliente,**regClientes=(void**)clientes;
    ofstream archReporteClientes("ReporteClientes.txt",ios::out);
    archReporteClientes<<fixed<<setprecision(2)<<"Clientes"<<endl;
    archReporteClientes<<left<<setw(12)<<"DNI"<<setw(45)<<"NOMBRE"<<"LINEA CRED."<<endl;
    for (int i=0;regClientes[i];i++) {
        regCliente=(void**)(regClientes[i]);
        archReporteClientes<<left<<setw(12)<<*(int*)(regCliente[0])<<setw(45)<<(char*)(regCliente[1]);
        archReporteClientes<<right<<setw(8)<<*(double*)(regCliente[3])<<endl;
    }
}

void imprimereporte(void* clientes) {
    void** regClientes=(void**)clientes;
    ofstream archReporte("ReporteDePedidos.txt",ios::out);
    archReporte<<fixed<<setprecision(2)<<setfill('=')<<setw(70)<<" "<<setfill(' ')<<endl;
    for (int i=0;regClientes[i];i++) {
        void **regCliente=(void**)(regClientes[i]);
        archReporte<<left<<setw(12)<<"DNI"<<setw(45)<<"NOMBRE"<<"CREDITO"<<endl;
        archReporte<<setw(12)<<*(int*)(regCliente[0])<<setw(45)<<(char*)(regCliente[1]);
        archReporte<<right<<setw(8)<<*(double*)(regCliente[3])<<endl;
        archReporte<<setfill('-')<<setw(70)<<" "<<setfill(' ')<<endl;
        archReporte<<"Pedidos atendidos:"<<endl;
        archReporte<<setfill('-')<<setw(70)<<" "<<setfill(' ')<<endl;
        archReporte<<left<<setw(12)<<"CODIGO"<<setw(12)<<"CANTIDAD"<<"TOTAL"<<endl;
        archReporte<<setfill('-')<<setw(70)<<" "<<setfill(' ')<<endl;
        if (regCliente[2]) ImprimirPedidosCliente(regCliente[2],archReporte);
    }
}

void ImprimirPedidosCliente(void* pedidosCliente,ofstream& archReporte) {
    void** regPedidosCliente=(void**)pedidosCliente;
    for (int i=0;regPedidosCliente[i];i++) {
        void** regPedido=(void**)(regPedidosCliente[i]);
        archReporte<<left<<setw(12)<<(char*)(regPedido[0])<<right<<setw(5)<<*(int*)(regPedido[1]);
        archReporte<<setw(18)<<*(double*)(regPedido[2])<<endl;
    }
}