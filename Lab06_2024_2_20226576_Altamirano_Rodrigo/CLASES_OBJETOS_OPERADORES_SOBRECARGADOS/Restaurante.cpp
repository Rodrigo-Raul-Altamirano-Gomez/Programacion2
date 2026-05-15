//
// Created by hrodic on 14/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Restaurante.h"

Restaurante::Restaurante() {
    this->clientes=nullptr;
    this->cantidadDeClientes=0;
    this->capacidadDeClientes=0;
    this->platos=nullptr;
    this->cantidadDePlatos=0;
    this->capacidadDePlatos=0;
}

Restaurante& Restaurante::operator<(const char* nombreArchClientes) {
    ifstream archClientes(nombreArchClientes,ios::in);
    Cliente cliente;
    while (archClientes>>cliente) {
        if (this->cantidadDeClientes==this->capacidadDeClientes) incrementarMemClientes();
        this->clientes[this->cantidadDeClientes]=cliente;
        this->cantidadDeClientes++;
    }
    return *this;
}

void Restaurante::incrementarMemClientes() {
    capacidadDeClientes+=5;
    if (cantidadDeClientes==0) this->clientes=new Cliente[capacidadDeClientes];
    else {
        Cliente* clientesAux=new Cliente[capacidadDeClientes];
        for (int i=0;i<cantidadDeClientes;i++) clientesAux[i]=clientes[i];
        delete[] clientes;
        clientes=clientesAux;
    }
}

Restaurante& Restaurante::operator<=(const char* nombreArchPlatos) {
    ifstream archPlatos(nombreArchPlatos,ios::in);
    Plato plato;
    while (archPlatos>>plato) {
        if (this->cantidadDePlatos==this->capacidadDePlatos) incrementarMenPlatos();
        this->platos[this->cantidadDePlatos]=plato;
        this->cantidadDePlatos++;
    }
    return *this;
}

void Restaurante::incrementarMenPlatos() {
    capacidadDePlatos+=5;
    if (cantidadDePlatos==0) platos=new Plato[capacidadDePlatos];
    else {
        Plato* platosAux=new Plato[capacidadDePlatos];
        for (int i=0;i<cantidadDePlatos;i++) platosAux[i]=platos[i];
        delete[] platos;
        platos=platosAux;
    }
}

Restaurante& Restaurante::operator<<=(const char* nombreArchPedidos) {
    ifstream archPedidos(nombreArchPedidos,ios::in);
    int numPedido,dniCliente,posCliente,posPlato,cantPlatoPedido;
    while (archPedidos>>numPedido) {
        char car,codPlato[20];
        archPedidos>>car>>dniCliente;
        posCliente=buscarCliente(dniCliente);
        if (posCliente>=0) {
            while (archPedidos.get()!='\n') {
                archPedidos.getline(codPlato,20,',');
                archPedidos>>cantPlatoPedido;
                posPlato=buscarPlato(codPlato);
                if (posPlato>=0) actualizarAtributos(posCliente,posPlato,cantPlatoPedido);
            }
        }
    }
    return *this;
}

int Restaurante::buscarCliente(int dniCliente) const {
    for (int i=0;i<cantidadDeClientes;i++) {
        if (dniCliente==clientes[i].getDni()) return i;
    }
    return -1;
}

int Restaurante::buscarPlato(const char* codPlato) const {
    for (int i=0;i<cantidadDePlatos;i++) {
        if (strcmp(codPlato,platos[i].getCodigo())==0) return i;
    }
    return -1;
}

void Restaurante::actualizarAtributos(int posCliente,int posPlato,int cantPlatoPedido) {
    Cliente& cliente=clientes[posCliente];
    Plato& plato=platos[posPlato];
    plato.setTotalEsperado(plato.getPrecio()*plato.getPreparados());
    if (plato.getAtendidos()+cantPlatoPedido<=plato.getPreparados()) {
        double pagoCliente=(1-cliente.getDescuento()/100)*(((1-plato.getDescuento()/100)*plato.getPrecio())
            *cantPlatoPedido);
        clientes[posCliente].incrementarTotal(pagoCliente);
        plato.incrementarAntendidos(cantPlatoPedido);
        plato.incrementarTotalBruto(plato.getPrecio()*cantPlatoPedido);
        plato.incrementarTotalNeto(pagoCliente);
    }
    else plato.incrementarNoAntendidos(cantPlatoPedido);
}

const Restaurante &Restaurante::operator>>(const char* nombreArchReporte) const {
    ofstream archReporte(nombreArchReporte,ios::out);
    imprimirEncabezado(archReporte);
    for (int i=0;i<this->cantidadDePlatos;i++) {
        archReporte<<right<<setw(2)<<i+1<<")"<<setw(2)<<" ";
        archReporte<<this->platos[i];
    }
    archReporte<<setfill('=')<<setw(200)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(125)<<"RELACION DE CLIENTES VENDIDOS"<<endl;
    archReporte<<setfill('-')<<setw(200)<<" "<<setfill(' ')<<endl;
    archReporte<<left<<setw(5)<<"No."<<setw(12)<<"DNI"<<setw(45)<<"NOMBRE"<<setw(30)<<"DISTRITO";
    archReporte<<setw(15)<<"DESCUENTO"<<"TOTAL PAGADO"<<endl;
    archReporte<<setfill('-')<<setw(200)<<" "<<setfill(' ')<<endl;
    for (int i=0;i<this->cantidadDeClientes;i++) {
        archReporte<<right<<setw(2)<<i+1<<")"<<setw(2)<<" ";
        archReporte<<this->clientes[i];
    }
    return *this;
}

void Restaurante::imprimirEncabezado(ofstream& archReporte) const {
    archReporte<<fixed<<setprecision(2)<<setw(120)<<"RESTAURANTE 1INF25"<<endl;
    archReporte<<setw(117)<<"VENTAS DEL DIA"<<endl;
    archReporte<<setfill('=')<<setw(200)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(124)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    archReporte<<setfill('-')<<setw(200)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(130)<<"PLATOS"<<setw(40)<<"TOTAL"<<endl;
    archReporte<<left<<setw(5)<<"No."<<setw(12)<<"CODIGO"<<setw(45)<<"NOMBRE"<<setw(10)<<"PRECIO";
    archReporte<<setw(15)<<"CATEGORIA"<<setw(15)<<"PREPARADOS"<<setw(15)<<"DESCUENTO"<<setw(15)<<"ATENDIDOS";
    archReporte<<setw(15)<<"NO ATENDIDOS"<<setw(15)<<"ESPERADO"<<setw(12)<<"BRUTO"<<"NETO"<<endl;
    archReporte<<setfill('-')<<setw(200)<<" "<<setfill(' ')<<endl;
}

Restaurante::~Restaurante() {
    delete[] this->clientes;
    delete[] this->platos;
}
