//
// Created by hrodic on 25/05/2026.
//
#include <iomanip>
#include "EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal() {
    this->cantidad_novelas=0;
}

void EstanteHorizontal::leerEstanteHorizontal(ifstream &archEstantes) {
    this->leerEstante(archEstantes);
}

int EstanteHorizontal::getAnchuraSobrante() const {
    int anchuraOcupada=0;
    for (int i=0;i<this->cantidad_novelas;i++) {
        anchuraOcupada+=this->novelas[i].getAnchura();
    }
    return this->getAltura()-anchuraOcupada;
}

int EstanteHorizontal::getAltura() const {
    return Estante::getAltura();
}

double EstanteHorizontal::getPesoMaximo() const {
    return Estante::getPesoMaximo();
}

double EstanteHorizontal::getPesoActual() const {
    return Estante::getPesoActual();
}

void EstanteHorizontal::insertarNovela(const Novela &novela) {
    this->novelas[this->cantidad_novelas]=novela;
    this->cantidad_novelas++;
    Estante::insertarNovela(novela);
}

void EstanteHorizontal::escribirEstanteHorizontal(ofstream &archReporte) const {
    archReporte<<"Codigo Estante: "<<left<<setw(10)<<this->getCodigo();
    archReporte<<"Cantidad de Libros: "<<this->cantidad_novelas<<endl<<right;
    archReporte<<"Anchura X Altura: "<<Estante::getAnchura()<<" x "<<Estante::getAltura()<<setw(4)<<" ";
    archReporte<<"Peso Maximo: "<<Estante::getPesoMaximo()<<" kg"<<endl;
    archReporte<<left<<setw(20)<<"Tipo: Horizontal"<<right<<"Peso Total: "<<Estante::getPesoActual()<<" kg"<<endl;
    archReporte<<setfill('-')<<setw(50)<<" "<<setfill(' ')<<endl;
    this->imprimirEspacios(archReporte);
    archReporte<<endl<<left<<setw(10)<<"CODIGO"<<setw(25)<<"NOMBRE"<<setw(7)<<"ANCHO"<<setw(7)<<"ALTO";
    archReporte<<"PESO"<<endl;
    archReporte<<setfill('.')<<setw(50)<<" "<<setfill(' ')<<endl;
    for (int i=0;i<this->cantidad_novelas;i++) archReporte<<this->novelas[i];
}

ifstream& operator>>(ifstream& archEstantes,EstanteHorizontal& estanteHorizontal) {
    estanteHorizontal.leerEstanteHorizontal(archEstantes);
    return archEstantes;
}

ofstream& operator<<(ofstream& archReporte,const EstanteHorizontal& estanteHorizontal) {
    estanteHorizontal.escribirEstanteHorizontal(archReporte);
    return archReporte;
}
