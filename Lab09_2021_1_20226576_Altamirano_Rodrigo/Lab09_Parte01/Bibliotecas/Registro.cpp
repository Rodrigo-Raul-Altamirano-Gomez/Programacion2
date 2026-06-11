//
// Created by hrodic on 8/06/2026.
//

#include "Registro.h"
#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"

Registro::Registro() {
    this->pfalta=nullptr;
}

void Registro::leeConductor(int licencia) {
    ifstream archConductores("ArchivosDeDatos/Conductores.csv",ios::in);
    char nombre[50],car;
    int licenciaActual;
    while (archConductores>>licenciaActual) {
        if (licenciaActual==licencia) break;
        else archConductores.ignore(50,'\n');
    }
    this->setLicencia(licencia);
    if (not archConductores.eof()) {
        archConductores>>car>>nombre;
        this->setNombre(nombre);
    }
}

void Registro::leeInfraccion(int codInfraccion) {
    ifstream archInfraciones("ArchivosDeDatos/Infracciones.csv",ios::in);
    int codInfraccionActual;
    while (archInfraciones>>codInfraccionActual) {
        if (codInfraccionActual==codInfraccion) break;
        else archInfraciones.ignore(200,'\n');
    }
    if (not archInfraciones.eof()) {
        if (codInfraccion/100==1) this->pfalta=new Leve;
        else if (codInfraccion/100==2) this->pfalta=new Grave;
        else this->pfalta=new MuyGrave;
        this->pfalta->lee(archInfraciones,codInfraccion);
    }
}

void Registro::imprimir(ofstream &archReporte) const {
    
}

Registro::~Registro() {
    delete this->pfalta;
}
