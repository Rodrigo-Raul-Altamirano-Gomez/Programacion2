//
// Created by hrodic on 8/05/2026.
//
#include "Libro.h"
#include "Estante.h"
#include "Biblioteca.h"
#include <iomanip>

void Biblioteca::cargar_libros() {
    ifstream archLibros("libros.csv",ios::in);
    Libro libro;
    this->cantidad_libros=0;
    while (archLibros>>libro) {
        this->libros[this->cantidad_libros]=libro;
        this->cantidad_libros++;
    }
}

void Biblioteca::cargar_estantes() {
    ifstream archEstantes("estantes.csv",ios::in);
    Estante estante;
    this->cantidad_estantes=0;
    while (archEstantes>>estante) {
        this->estantes[this->cantidad_estantes]=estante;
        this->cantidad_estantes++;
    }
}

void Biblioteca::posicionar_libros() {
    for (int i=0;i<this->cantidad_libros;i++) {
        for (int j=0;j<this->cantidad_estantes;j++) {
            if (this->estantes[j]+=this->libros[i]) break;
        }
    }
}

void Biblioteca::mostrar_datos() {
    ofstream archReporte("Reporte.txt",ios::out);
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(60)<<"INFORMACION DEL POSICIONAMIENTO DE LOS LIBROS"<<endl;
    archReporte<<setw(50)<<"EN LOS ESTANTES DE LA BIBLIOTECA"<<endl;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<"Cantidad de estantes: "<<this->cantidad_estantes<<endl;
    for (int i=0;i<this->cantidad_estantes;i++) {
        archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
        archReporte<<this->estantes[i];
    }
}
