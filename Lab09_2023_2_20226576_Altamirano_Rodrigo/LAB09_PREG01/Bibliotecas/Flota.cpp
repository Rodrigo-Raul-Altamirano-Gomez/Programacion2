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
    NVehiculo nvehiculo;
    while (archVehiculos>>tipo) {
        archVehiculos.ignore();
        if (tipo=='C') *nvehiculo=new Camion;
        else *nvehiculo=new Furgon;
        (*nvehiculo)->leer(archVehiculos);
        this->vflota.push_back(nvehiculo);
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
