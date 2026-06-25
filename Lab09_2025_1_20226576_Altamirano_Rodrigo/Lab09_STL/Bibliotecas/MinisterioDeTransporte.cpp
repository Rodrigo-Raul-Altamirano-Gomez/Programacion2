#include <iomanip>
//
// Created by hrodic on 25/06/2026.
//
using namespace std;
#include <algorithm>
#include "MinisterioDeTransporte.h"

void MinisterioDeTransporte::cargaDeInfracciones(const std::string& nombreArchivoInfracciones) {
    ifstream archInfracciones(nombreArchivoInfracciones,ios::in);
    Infraccion infraccion;
    while (infraccion.leer(archInfracciones)) {
        this->tablaInfracciones.push_back(infraccion);
    }
    this->tablaInfracciones.sort();
}

void MinisterioDeTransporte::cargaEmpresas(const std::string& nombreArchivoEmpresas) {
    ifstream archEmpresas(nombreArchivoEmpresas,ios::in);
    Empresa empresa;
    while (empresa.leer(archEmpresas)) {
        this->listaEmpresas.push_back(empresa);
    }
    this->listaEmpresas.sort();
}

void MinisterioDeTransporte::cargaVehiculos(const std::string& nombreArchivoVehiculos) {
    ifstream archVehiculos(nombreArchivoVehiculos,ios::in);
    int dni;
    while (archVehiculos>>dni) {
        Vehiculo vehiculo;
        Empresa empresaClave(dni);
        archVehiculos.ignore();
        vehiculo.leer(archVehiculos);
        auto empresa=find(this->listaEmpresas.begin(),this->listaEmpresas.end(),empresaClave);
        if (empresa!=this->listaEmpresas.end()) (*empresa).añadirVehiculo(vehiculo);
    }
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const std::string& nombreArchivoMultas) {
    ifstream archMultas(nombreArchivoMultas,ios::in);
    Multa multa;
    while (multa.leer(archMultas)) {
        Infraccion infraccionClave(multa.getCodMulta());
        auto empresa=this->buscarEmpresaPorPlaca(multa.getPlaca());
        auto infraccion=find(this->tablaInfracciones.begin(),this->tablaInfracciones.end(),infraccionClave);
        if (empresa!=this->listaEmpresas.end() and infraccion!=this->tablaInfracciones.end()) {
            multa.setMulta((*infraccion).getMulta());
            (*empresa).anadirMulta(multa);
        }
    }
}

std::list<Empresa>::iterator MinisterioDeTransporte::buscarEmpresaPorPlaca(const std::string &placa) {
    for (auto empresa=this->listaEmpresas.begin();empresa!=this->listaEmpresas.end();empresa++) {
        const map<string,Vehiculo> vehiculos=(*empresa).getVehiculos();
        if (vehiculos.find(placa)!=vehiculos.end()) return empresa;
    }
    return this->listaEmpresas.end();
}

void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const std::string& nombreArchivoReporte) const {
    ofstream archReporte(nombreArchivoReporte,ios::out);
    MinisterioDeTransporte::rellenarLinea('=',archReporte);
    archReporte<<setw(75)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    MinisterioDeTransporte::rellenarLinea('-',archReporte);
    for (auto empresa=this->listaEmpresas.begin();empresa!=this->listaEmpresas.end();empresa++) {
        (*empresa).imprimir(archReporte);
        MinisterioDeTransporte::rellenarLinea('=',archReporte);
    }
}

void MinisterioDeTransporte::rellenarLinea(char carRelleno, std::ofstream &output) {
    output<<setfill(carRelleno)<<setw(100)<<carRelleno<<setfill(' ')<<endl;
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (auto empresa=this->listaEmpresas.begin();empresa!=this->listaEmpresas.end();empresa++) {
        (*empresa).eliminarInfraccionesPagadas();
    }
}
