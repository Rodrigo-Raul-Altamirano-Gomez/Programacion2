//
// Created by hrodic on 23/06/2026.
//

#include "Estante.h"
using namespace std;
#include <iomanip>

void Estante::setDisponible(double disponible) {
    this->disponible=disponible;
}

double Estante::getDisponible() const {
    return this->disponible;
}

bool Estante::leer(std::ifstream &archEstantes) {
    int id;
    char car;
    archEstantes>>id;
    if (archEstantes) {
        this->id=id;
        archEstantes>>car>>this->capacidad;
        this->disponible=this->capacidad;
        return true;
    }
    return false;
}

void Estante::vaciar() {
    this->vlibros.clear();
}

void Estante::cargar(NLibro nlibro) {
    this->vlibros.push_back(nlibro);
    this->disponible-=(*nlibro)->getPeso();
}

bool Estante::operator<=(const Estante &estante) const {
    return this->disponible<=estante.disponible;
}

void Estante::imprimir(std::ofstream &archReporte) {
    archReporte<<setw(10)<<" "<<"Estante: "<<this->id<<endl;
    archReporte<<setw(10)<<" "<<"Capacidad: "<<left<<setw(7)<<this->capacidad;
    archReporte<<"Disponible: "<<this->disponible<<endl;
    archReporte<<setw(10)<<" "<<setfill('=')<<setw(50)<<" "<<setfill(' ')<<endl;
    for (auto iterador=this->vlibros.begin();iterador!=this->vlibros.end();iterador++) {
        (*(*iterador))->imprimir(archReporte);
        archReporte<<endl;
    }
}

std::ofstream& operator<<(std::ofstream& archReporte,Estante estante) {
    estante.imprimir(archReporte);
    return archReporte;
}
