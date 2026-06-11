//
// Created by hrodic on 3/06/2026.
//
#include <cstring>
#include <iomanip>
#include "Flota.h"

Flota::Flota() {
    this->n_drones_velocidad=0;
    this->n_drones_semaforo=0;
    this->n_drones_estacionamiento=0;
}

void Flota::cargar_drone(ifstream& input,const char* tipo) {
    char tipo_dron[20];
    while (true) {
        input.getline(tipo_dron,20,',');
        if (input.eof()) break;
        if (strcmp(tipo_dron,tipo)==0) {
            if (strcmp(tipo,"Velocidad")==0) {
                input>>this->drones_velocidad[this->n_drones_velocidad];
                this->n_drones_velocidad++;
            } else if (strcmp(tipo,"Semaforo")==0) {
                input>>this->drones_semaforo[this->n_drones_semaforo];
                this->n_drones_semaforo++;
            } else {
                input>>this->drones_estacionamiento[this->n_drones_estacionamiento];
                this->n_drones_estacionamiento++;
            }
        } else input.ignore(100,'\n');
    }
}

int Flota::buscarDroneVelocidad(const char* id) {
    for (int i=0;i<this->n_drones_velocidad;i++) {
        if (strcmp(this->drones_velocidad[i].get_id(),id)==0) return i;
    }
    return -1;
}

int Flota::buscarDroneSemaforo(const char* id) {
    for (int i=0;i<this->n_drones_semaforo;i++) {
        if (strcmp(this->drones_semaforo[i].get_id(),id)==0) return i;
    }
    return -1;
}

int Flota::buscarDroneEstacionamiento(const char* id) {
    for (int i=0;i<this->n_drones_estacionamiento;i++) {
        if (strcmp(this->drones_estacionamiento[i].get_id(),id)==0) return i;
    }
    return -1;
}

void Flota::actualizarDronesInfracciones(ifstream& arch) {
    char id_dron[20],car;
    int posDron,valor;
    Infraccion infraccion;
    while (true) {
        arch.getline(id_dron,20,',');
        if (arch.eof()) break;
        arch>>infraccion>>valor;
        arch.ignore();
        if (id_dron[1]=='V') posDron=this->buscarDroneVelocidad(id_dron);
        else if (id_dron[1]=='S') posDron=this->buscarDroneSemaforo(id_dron);
        else posDron=this->buscarDroneEstacionamiento(id_dron);
        if (posDron>=0) {
            if (id_dron[1]=='V') {
                infraccion.completar_infraccion(id_dron[1],valor,this->drones_velocidad[posDron].get_velocidad_maxima());
                this->drones_velocidad[posDron].insertar_infraccion(infraccion);
            } else if (id_dron[1]=='S') {
                infraccion.completar_infraccion(id_dron[1],valor,this->drones_semaforo[posDron].get_luz_roja());
                this->drones_semaforo[posDron].insertar_infraccion(infraccion);
            } else {
                infraccion.completar_infraccion(id_dron[1],valor,this->drones_estacionamiento[posDron].get_zona_carga());
                this->drones_estacionamiento[posDron].insertar_infraccion(infraccion);
            }
        }
    }
}

void Flota::obtener_info_multas(int &cantidad_multas, double &monto_total) {
    cantidad_multas=0;
    monto_total=0;
    for (int i=0;i<this->n_drones_velocidad;i++) {
        this->drones_velocidad[i].obtener_multas(cantidad_multas,monto_total);
    }
    for (int i=0;i<this->n_drones_semaforo;i++) {
        this->drones_semaforo[i].obtener_multas(cantidad_multas,monto_total);
    }
    for (int i=0;i<this->n_drones_estacionamiento;i++) {
        this->drones_estacionamiento[i].obtener_multas(cantidad_multas,monto_total);
    }
}

void Flota::imprimir(ofstream& output) const {
    output<<"Velocidad"<<setw(7)<<this->n_drones_velocidad<<endl;
    for (int i=0;i<this->n_drones_velocidad;i++) output<<this->drones_velocidad[i]<<endl;
    output<<"Semaforo"<<setw(7)<<this->n_drones_semaforo<<endl;
    for (int i=0;i<this->n_drones_semaforo;i++) output<<this->drones_semaforo[i]<<endl;
    output<<"Estacionamiento"<<setw(7)<<this->n_drones_estacionamiento<<endl;
    for (int i=0;i<this->n_drones_estacionamiento;i++) output<<this->drones_estacionamiento[i]<<endl;
}

ofstream& operator<<(ofstream& arch,const Flota& flota) {
    flota.imprimir(arch);
    return arch;
}