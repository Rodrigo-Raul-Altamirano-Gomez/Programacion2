//
// Created by hrodic on 12/06/2026.
//

#include "Flota.h"
#include <fstream>
#include <iomanip>

#include "Camion.h"
#include "Furgon.h"
using namespace std;

void Flota::cargaflota() {
    ifstream archVehiculos("ArchivosDeDatos/Vehiculos.csv",ios::in);
    char tipoVehiculo;
    Vehiculo* vehiculo;
    while (archVehiculos>>tipoVehiculo) {
        archVehiculos.ignore();
        if (tipoVehiculo=='C') vehiculo=new Camion;
        else vehiculo=new Furgon;
        vehiculo->leer(archVehiculos);
        this->lista.agregarVehiculo(vehiculo);
    }
}

void Flota::muestracarga() const {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2)<<setw(40)<<"REPORTEDE FLOTA"<<endl;
    archReporte<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl<<endl;
    this->lista.imprimir(archReporte);
}
