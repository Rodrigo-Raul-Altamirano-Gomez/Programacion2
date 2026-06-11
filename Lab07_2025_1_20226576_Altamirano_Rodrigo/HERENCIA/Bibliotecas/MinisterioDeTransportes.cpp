//
// Created by hrodic on 3/06/2026.
//
#include <cstring>
#include <iomanip>
#include "MinisterioDeTransportes.h"

MinisterioDeTransportes::MinisterioDeTransportes() {
    for (int i=0;i<10;i++) this->zonas[i]=nullptr;
    this->cantidad_centros=0;
}

void MinisterioDeTransportes::apertura_archivo_leer(ifstream& arch,const char* nombre_archivo) {
    arch.open(nombre_archivo,ios::in);
}

void MinisterioDeTransportes::apertura_archivo_imprimir(ofstream& arch,const char* nombre_archivo) {
    arch.open(nombre_archivo,ios::out);
}

int MinisterioDeTransportes::obtener_ruta(const char* carpeta_base,const char* tipo,const char* zona,char* ruta) const {
    char ruta_nueva[200];
    strcat(ruta_nueva,carpeta_base);
    strcat(ruta_nueva,tipo);
    strcat(ruta_nueva,"_");
    strcat(ruta_nueva,zona);
    strcat(ruta_nueva,".csv");
    strcpy(ruta,ruta_nueva);
    return 1;
}

void MinisterioDeTransportes::cargar_drones(const char* ruta_base) {
    ifstream archZonas,arch;
    char zona[30],ruta[200];
    this->apertura_archivo_leer(archZonas,"ArchivosDeDatos/zonas.txt");
    while (archZonas>>zona) {
        this->obtener_ruta(ruta_base,"Drones",zona,ruta);
        this->apertura_archivo_leer(arch,ruta);
        this->centros[this->cantidad_centros].leer(arch,"Velocidad");
        this->centros[this->cantidad_centros].leer(arch,"Semaforo");
        this->centros[this->cantidad_centros].leer(arch,"Estacionamiento");
        this->cantidad_centros++;
    }
}

void MinisterioDeTransportes::procesar_todos_los_eventos(const char* ruta_base) {
    ifstream archZonas,arch;
    char zona[30],ruta[200];
    this->apertura_archivo_leer(archZonas,"ArchivosDeDatos/zonas.txt");
    this->cantidad_centros=0;
    while (archZonas>>zona) {
        this->obtener_ruta(ruta_base,"Eventos",zona,ruta);
        this->apertura_archivo_leer(arch,ruta);
        this->centros[this->cantidad_centros].cargar_infracciones(arch);
        this->zonas[this->cantidad_centros]=new char[strlen(zona)+1];
        strcpy(this->zonas[this->cantidad_centros],zona);
        this->cantidad_centros++;
    }
}

void MinisterioDeTransportes::imprimir(const char* nombre_archivo) {
    ofstream arch;
    this->apertura_archivo_imprimir(arch,nombre_archivo);
    arch<<setw(5)<<this->cantidad_centros<<endl<<fixed<<setprecision(2);
    for (int i=0;i<this->cantidad_centros;i++) {
        arch<<left<<setw(20)<<this->zonas[i]<<right;
        arch<<this->centros[i]<<endl;
    }
}

MinisterioDeTransportes::~MinisterioDeTransportes() {
    for (int i=0;i<10;i++) delete[] this->zonas[i];
}
