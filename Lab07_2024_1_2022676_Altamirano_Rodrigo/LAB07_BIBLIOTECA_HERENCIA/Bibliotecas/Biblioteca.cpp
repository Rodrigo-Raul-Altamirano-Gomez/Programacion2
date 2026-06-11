//
// Created by hrodic on 25/05/2026.
//
#include <fstream>
#include "Biblioteca.h"
#include <iomanip>
using namespace std;

Biblioteca::Biblioteca() {
    this->cantidad_estantes_verticales=0;
    this->cantidad_estantes_horizontales=0;
    this->cantidad_total_enciclopedias=0;
    this->cantidad_total_novelas=0;
}

void Biblioteca::cargar_libros() {
    ifstream archLibros("ArchivosDeDatos/libros2.csv",ios::in);
    char tipo;
    while (archLibros>>tipo) {
        archLibros.ignore();
        if (tipo=='E') {
            archLibros>>this->enciclopedias[this->cantidad_total_enciclopedias];
            this->cantidad_total_enciclopedias++;
        }
        else {
            archLibros>>this->novelas[this->cantidad_total_novelas];
            this->cantidad_total_novelas++;
        }
    }
}

void Biblioteca::cargar_estantes() {
    ifstream archEstantes("ArchivosDeDatos/estantes2.csv",ios::in);
    char tipo;
    while (archEstantes>>tipo) {
        archEstantes.ignore();
        if (tipo=='V') {
            archEstantes>>this->estantesVerticales[this->cantidad_estantes_verticales];
            this->cantidad_estantes_verticales++;
        }
        else {
            archEstantes>>this->estantesHorizontales[this->cantidad_estantes_horizontales];
            this->cantidad_estantes_horizontales++;
        }
    }
}

void Biblioteca::posicionar_libros() {
        this->posicionarEnciclopedias();
    this->posicionarNovelas();
}

void Biblioteca::posicionarEnciclopedias() {
    for (int i=0;i<this->cantidad_total_enciclopedias;i++) {
        int alturaEnciclopedia=this->enciclopedias[i].getAltura(),anchuraEnciclopedia=this->enciclopedias[i].getAnchura();
        double pesoEnciclopedia=this->enciclopedias[i].getPeso();
        for (int j=0;j<this->cantidad_estantes_verticales;j++) {
            int alturaSobrante=this->estantesVerticales[j].getAlturaSobrante();
            int anchuraEstanteVertical=this->estantesVerticales[j].getAnchura();
            double pesoActualEstante=this->estantesVerticales[j].getPesoActual();
            double pesoMaximoEstante=this->estantesVerticales[j].getPesoMaximo();
            if (alturaSobrante>=alturaEnciclopedia and anchuraEstanteVertical>=anchuraEnciclopedia and
                pesoActualEstante+pesoEnciclopedia<=pesoMaximoEstante) {
                this->enciclopedias[i].setColocado(true);
                this->estantesVerticales[j].insertarEnciclopedia(this->enciclopedias[i]);
                break;
            }
        }
    }
}

void Biblioteca::posicionarNovelas() {
    for (int i=0;i<this->cantidad_total_novelas;i++) {
        int anchuraNovela=this->novelas[i].getAnchura(),alturaNovela=this->novelas[i].getAltura();
        double pesoNovela=this->novelas[i].getPeso();
        for (int j=0;j<this->cantidad_estantes_horizontales;j++) {
            int anchuraSobrante=this->estantesHorizontales[j].getAnchuraSobrante();
            int alturaEstanteHorizontal=this->estantesHorizontales[j].getAltura();
            double pesoActualEstante=this->estantesHorizontales[j].getPesoActual();
            double pesoMaximoEstante=this->estantesHorizontales[j].getPesoMaximo();
            if (anchuraSobrante>=anchuraNovela and alturaEstanteHorizontal>=alturaNovela and
                pesoActualEstante+pesoNovela<=pesoMaximoEstante) {
                this->novelas[i].setColocado(true);
                this->estantesHorizontales[j].insertarNovela(this->novelas[i]);
                break;
                }
        }
    }
}

void Biblioteca::mostrar_datos() const {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2);
    this->rellenarLinea('=',archReporte);
    archReporte<<setw(45)<<"Informacion del posicionamiento de Libros"<<endl;
    archReporte<<setw(40)<<"en los estantes de la Biblioteca"<<endl;
    this->rellenarLinea('=',archReporte);
    this->imprimirEstantes(archReporte);
    this->rellenarLinea('=',archReporte);
    archReporte<<"Informacion de todos los Libros:"<<endl;
    this->imprimirLibros(archReporte);
}

void Biblioteca::rellenarLinea(char carRelleno,ofstream& archReporte) const {
    for (int i=0;i<50;i++) archReporte.put(carRelleno);
    archReporte<<endl;
}

void Biblioteca::imprimirEstantes(ofstream &archReporte) const {;
    archReporte<<"Cantidad de Estantes: "<<this->cantidad_estantes_horizontales+this->cantidad_estantes_verticales<<endl;
    for (int i=0;i<this->cantidad_estantes_horizontales;i++) {
        this->rellenarLinea('-',archReporte);
        archReporte<<this->estantesHorizontales[i];
    }
    for (int i=0;i<this->cantidad_estantes_verticales;i++) {
        this->rellenarLinea('-',archReporte);
        archReporte<<this->estantesVerticales[i];
    }
}

void Biblioteca::imprimirLibros(ofstream &archReporte) const {
    archReporte<<"Cantidad de Libros Total: "<<this->cantidad_total_novelas+this->cantidad_total_enciclopedias<<endl;
    for (int i=0;i<this->cantidad_total_novelas;i++) archReporte<<this->novelas[i];
    for (int i=0;i<this->cantidad_total_enciclopedias;i++) archReporte<<this->enciclopedias[i];
}
