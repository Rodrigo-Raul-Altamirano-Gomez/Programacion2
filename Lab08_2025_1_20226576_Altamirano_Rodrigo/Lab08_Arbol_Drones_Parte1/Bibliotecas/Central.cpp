//
// Created by hrodic on 15/06/2026.
//

#include "Central.h"

#include <cstring>
#include <iomanip>

#include "DroneEstacionamiento.h"
#include "DroneSemaforo.h"
#include "DroneVelocidad.h"

void Central::carga() {
    ifstream archDrones("ArchivosDeDatos/Drones.csv",ios::in);
    char tipoDron[20];
    Dron* dron;
    while (true) {
        archDrones.getline(tipoDron,20,',');
        if (archDrones.eof()) break;
        if (strcmp(tipoDron,"Velocidad")==0) dron=new DroneVelocidad;
        else if (strcmp(tipoDron,"Semaforo")==0) dron=new DroneSemaforo;
        else dron=new DroneEstacionamiento;
        dron->leer(archDrones);
        this->ADrones.insertarABB(dron);
    }
}

void Central::muestra() const {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2)<<setw(35)<<"REPORTE DE DRONES"<<endl;
    archReporte<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(5)<<" "<<left<<setw(10)<<"Codigo"<<setw(15)<<"Ubicacion"<<setw(12)<<"Capacidad";
    archReporte<<"Velocidad/Zona/Luz"<<endl;
    archReporte<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl;
    this->ADrones.imprimirABB(archReporte);
}
