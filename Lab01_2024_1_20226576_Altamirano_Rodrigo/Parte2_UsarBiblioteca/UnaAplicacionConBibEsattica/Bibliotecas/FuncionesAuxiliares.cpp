//
// Created by hrodic on 9/04/2026.
//

#include "FuncionesAuxiliares.h"

void AperturaArchivoLectura(ifstream& archLectura,const char* nombreArchivo) {
    archLectura.open(nombreArchivo,ios::in);
    if (not archLectura.is_open()) cout<<"Error al abrir el archivo: "<<nombreArchivo<<endl;
}

void AperturaArchivoEscritura(ofstream& archEscritura,const char* nombreArchivo) {
    archEscritura.open(nombreArchivo,ios::out);
    if (not archEscritura.is_open()) cout<<"Error al abrir el archivo: "<<nombreArchivo<<endl;
}