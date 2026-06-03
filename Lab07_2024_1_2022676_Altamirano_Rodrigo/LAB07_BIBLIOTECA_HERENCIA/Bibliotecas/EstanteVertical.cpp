//
// Created by hrodic on 25/05/2026.
//
#include <iomanip>
#include "EstanteVertical.h"

EstanteVertical::EstanteVertical() {
    this->cantidad_enciclopedias=0;
}

void EstanteVertical::leerEstanteVertical(ifstream &archEstantes) {
    this->leerEstante(archEstantes);
}

int EstanteVertical::getAlturaSobrante() const {
    int alturaOcupada=0;
    for (int i=0;i<this->cantidad_enciclopedias;i++) {
        alturaOcupada+=this->enciclopedias[i].getAltura();
    }
    return this->getAltura()-alturaOcupada;
}

int EstanteVertical::getAnchura() const {
    return Estante::getAnchura();
}

double EstanteVertical::getPesoMaximo() const {
    return Estante::getPesoMaximo();
}

double EstanteVertical::getPesoActual() const {
    return Estante::getPesoActual();
}

void EstanteVertical::insertarEnciclopedia(const Enciclopedia &enciclopedia) {
    this->enciclopedias[this->cantidad_enciclopedias]=enciclopedia;
    this->cantidad_enciclopedias++;
    Estante::insertarEnciclopedia(enciclopedia);
}

void EstanteVertical::imprimirEstanteVertical(ofstream &archReporte) const {
    archReporte<<"Codigo Estante: "<<left<<setw(10)<<this->getCodigo();
    archReporte<<"Cantidad de Libros: "<<this->cantidad_enciclopedias<<endl<<right;
    archReporte<<"Anchura X Altura: "<<Estante::getAnchura()<<" x "<<Estante::getAltura()<<setw(4)<<" ";
    archReporte<<"Peso Maximo: "<<Estante::getPesoMaximo()<<" kg"<<endl;
    archReporte<<left<<setw(20)<<"Tipo: Vertical"<<right<<"Peso Total: "<<Estante::getPesoActual()<<" kg"<<endl;
    archReporte<<setfill('-')<<setw(50)<<" "<<setfill(' ')<<endl;
    this->imprimirEspacios(archReporte);
    archReporte<<endl<<left<<setw(10)<<"CODIGO"<<setw(25)<<"NOMBRE"<<setw(7)<<"ANCHO"<<setw(7)<<"ALTO";
    archReporte<<"PESO"<<endl;
    archReporte<<setfill('.')<<setw(50)<<" "<<setfill(' ')<<endl;
    for (int i=0;i<this->cantidad_enciclopedias;i++) archReporte<<this->enciclopedias[i];
}

ifstream& operator>>(ifstream& archEstantes,EstanteVertical& estanteVertical) {
    estanteVertical.leerEstanteVertical(archEstantes);
    return archEstantes;
}

ofstream& operator<<(ofstream& archReporte,const EstanteVertical& estanteVertical) {
    estanteVertical.imprimirEstanteVertical(archReporte);
    return  archReporte;
}