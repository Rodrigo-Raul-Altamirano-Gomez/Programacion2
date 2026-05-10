//
// Created by hrodic on 10/05/2026.
//
#include <iostream>
#include "Funciones.h"

void cargarUsuarios(Usuario*& arrUsuarios) {
    ifstream archUsuarios("Usuarios.csv",ios::in);
    Usuario bufferUsuarios[40];
    int cantUsuarios=0;
    while (archUsuarios>>bufferUsuarios[cantUsuarios]) {
        cantUsuarios++;
    }
    arrUsuarios=new Usuario[cantUsuarios+1];
    for (int i=0;i<cantUsuarios;i++) arrUsuarios[i]=bufferUsuarios[i];
    arrUsuarios[cantUsuarios].setCarne(0);
}

void cargarLibros(Libro*& arrLibros) {
    ifstream archLibros("Libros.csv",ios::in);
    Libro bufferLibros[45],libro;
    int cantLibros=0;
    while (archLibros>>libro) {
        if (libro.getStock()>0) {
            bufferLibros[cantLibros]=libro;
            cantLibros++;
        }
    }
    arrLibros=new Libro[cantLibros+1];
    for (int i=0;i<cantLibros;i++) arrLibros[i]=bufferLibros[i];
    arrLibros[cantLibros].setPrecio(0);
}

void procesarPrestamos(Usuario* arrUsuarios,Libro* arrLibros) {
    ifstream archPrestamos("RegistroDePrestamos.csv",ios::in);
    LibroPrestado libroPrestado;
    while (archPrestamos>>libroPrestado) {
        int posUsuario=libroPrestado.buscarUsuario(arrUsuarios);
        int posLibro=libroPrestado.buscarLibro(arrLibros);
        if (posUsuario>=0 and posLibro>=0) {
            arrUsuarios[posUsuario]+=libroPrestado;
            arrLibros[posLibro]+=libroPrestado;
        }
    }
}

void determinarDeudas(Usuario* arrUsuarios) {
    int dia,mes,anio,fechaActual;
    char car;
    cout<<"Ingrese la fecha: ";
    cin>>dia>>car>>mes>>car>>anio;
    fechaActual=dia+mes*100+anio*10000;
    for (int i=0;arrUsuarios[i].getCarne()>0;i++) {
        arrUsuarios[i]*fechaActual;
    }
}

void emitirReporteUsuarios(const Usuario* arrUsuarios) {
    ofstream archRepUsuarios("ReporteUsuarios.txt",ios::out);
    for (int i=0;arrUsuarios[i].getCarne()>0;i++) {
        archRepUsuarios<<arrUsuarios[i];
    }
}

void emitirReporteLibros(const Libro* arrLibros) {
    ofstream archRepLibros("ReporteLibros.txt",ios::out);
    for (int i=0;arrLibros[i].getPrecio()>0;i++) {
        archRepLibros<<arrLibros[i];
    }
}
