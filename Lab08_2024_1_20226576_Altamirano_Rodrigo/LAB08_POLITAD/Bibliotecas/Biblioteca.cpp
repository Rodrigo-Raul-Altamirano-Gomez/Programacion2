//
// Created by hrodic on 14/06/2026.
//

#include "Biblioteca.h"

#include <iomanip>

#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"

void Biblioteca::carga() {
    ifstream archEstantes("ArchivosDeDatos/Estantes2.csv",ios::in);
    int cantEstantes=0;
    while (this->AEstantes[cantEstantes].leer(archEstantes)) {
        cantEstantes++;
    }
}

void Biblioteca::llena() {
    ifstream archLibros("ArchivosDeDatos/Libros3.csv",ios::in);
    char tipo;
    Libro* libro;
    while (archLibros>>tipo) {
        archLibros.ignore();
        if (tipo=='E') libro=new Enciclopedia;
        else if (tipo=='N') libro=new Novela;
        else libro=new Revista;
        libro->lee(archLibros);
        if (not this->insertarLibro(libro)) delete libro;
    }
}

bool Biblioteca::insertarLibro(Libro *libro) {
    for (int i=0;this->AEstantes[i].getID()>=0;i++) {
        if (this->AEstantes[i].getPeso()+libro->getPeso()<=this->AEstantes[i].getCapacidad()) {
            this->AEstantes[i].insertarLibro(libro);
            return true;
        }
    }
    return false;
}

void Biblioteca::baja() {
    for (int i=0;this->AEstantes[i].getID()>=0;i++) {
        this->AEstantes[i].actualizarVigencia();
    }
}

void Biblioteca::muestra() const {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2)<<setw(10)<<" "<<"Estantes:"<<endl;
    for (int i=0;this->AEstantes[i].getID()>=0;i++) {
        this->AEstantes[i].imprimir(archReporte);
    }
}
