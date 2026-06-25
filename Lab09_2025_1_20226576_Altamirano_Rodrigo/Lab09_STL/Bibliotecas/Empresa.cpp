#include <iomanip>
//
// Created by hrodic on 25/06/2026.
//
using namespace std;
#include "Empresa.h"

Empresa::Empresa(int dni) {
    this->dni=dni;
}

int Empresa::getDni() const {
    return this->dni;
}

std::string Empresa::getNombre() const {
    return this->nombre;
}

std::string Empresa::getDistrito() const {
    return this->distrito;
}

std::map<std::string,Vehiculo> Empresa::getVehiculos() const {
    return this->vehiculos;
}

std::vector<Multa> Empresa::getMultasRecibidas() const {
    return this->multasRecibidas;
}

bool Empresa::leer(std::ifstream &input) {
    int dni;
    input>>dni;
    if (input) {
        this->dni=dni;
        input.ignore();
        getline(input,this->nombre,',');
        getline(input,this->distrito);
        return true;
    }
    return false;
}

void Empresa::imprimir(std::ofstream &output) const {
    output<<left<<"DNI: "<<setw(12)<<this->dni<<"NOMBRE: "<<setw(35)<<this->nombre;
    output<<"DISTRITO: "<<this->distrito<<endl;
    output<<"VEHICULOS DE LA EMPRESA:"<<endl;
    output<<setw(12)<<"PLACA"<<setw(15)<<"MARCA"<<"MODELO"<<endl;
    for (auto vehiculo=this->vehiculos.begin();vehiculo!=this->vehiculos.end();vehiculo++) {
        (*vehiculo).second.imprimir(output);
    }
    output<<setfill('-')<<setw(100)<<"-"<<setfill(' ')<<endl;
    output<<"MULTAS IMPUESTAS"<<endl;
    output<<setw(12)<<"PLACA"<<setw(25)<<"FECHA DE INFRACCION"<<setw(25)<<"CODIGO DE INFRACCION";
    output<<setw(10)<<"MULTA"<<setw(10)<<"PAGADA"<<"FECHA DE PAGO"<<endl;
    for (auto multa=this->multasRecibidas.begin();multa!=this->multasRecibidas.end();multa++) {
        (*multa).imprimir(output);
    }
}

bool Empresa::operator<(const Empresa &empresa) const {
    return this->dni<empresa.dni;
}

bool Empresa::operator==(const Empresa &empresa) const {
    return this->dni==empresa.dni;
}

void Empresa::añadirVehiculo(const Vehiculo &vehiculo) {
    this->vehiculos[vehiculo.getPlaca()]=vehiculo;
}

void Empresa::anadirMulta(const Multa &nuevaMulta) {
    auto multa=this->multasRecibidas.begin();
    for (;multa!=this->multasRecibidas.end();multa++) {
        if ((*multa).getFecha()<=nuevaMulta.getFecha()) break;
    }
    this->multasRecibidas.insert(multa,nuevaMulta);
}

void Empresa::eliminarInfraccionesPagadas() {
    auto multa=this->multasRecibidas.begin();
    while (multa!=this->multasRecibidas.end()) {
        if ((*multa).getPagada()) multa=this->multasRecibidas.erase(multa);
        else multa++;
    }
}
