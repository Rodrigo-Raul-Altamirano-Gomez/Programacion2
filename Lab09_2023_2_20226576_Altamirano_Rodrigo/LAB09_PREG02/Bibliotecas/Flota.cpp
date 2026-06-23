#include <algorithm>
#include <iomanip>

#include "Camion.h"
#include "Furgon.h"
//
// Created by hrodic on 22/06/2026.
//
using namespace std;
#include <fstream>
#include "Flota.h"

void Flota::cargaflota() {
    ifstream archVehiculos("ArchivosDeDatos/Vehiculos.csv",ios::in);
    char tipo;
    while (archVehiculos>>tipo) {
        archVehiculos.ignore();
        NVehiculo nvehiculo;
        if (tipo=='C') *nvehiculo=new Camion;
        else *nvehiculo=new Furgon;
        (*nvehiculo)->leer(archVehiculos);
        this->vflota.push_back(nvehiculo);
    }
    sort(this->vflota.begin(),this->vflota.end());
}

void Flota::cargapedidos() {
    ifstream archPedidos("ArchivosDeDatos/Pedidos3.csv",ios::in);
    int cliente;
    NPedido pedido;
    NVehiculo nvehiculo;
    (*nvehiculo)=new Camion;
    while (archPedidos>>cliente) {
        archPedidos.ignore();
        pedido.leer(archPedidos);
        (*nvehiculo)->setCliente(cliente);
        auto nVehiculoCliente=find(this->vflota.begin(),this->vflota.end(),nvehiculo);
        Vehiculo* vehiculo=*(*nVehiculoCliente);
        if (nVehiculoCliente!=this->vflota.end() and vehiculo->disponible(pedido.getPeso())) {
            vehiculo->cargadeposito(pedido);
            vehiculo->setActCarga(vehiculo->getCargaActual()+pedido.getPeso());
        }
    }
}

void Flota::muestracarga() {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2)<<setw(40)<<"REPORTE DE FLOTA"<<endl;
    archReporte<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl<<endl;
    for (auto iterador=this->vflota.begin();iterador!=this->vflota.end();iterador++) {
        (*(*iterador))->imprimir(archReporte);
        archReporte<<endl;
    }
}
