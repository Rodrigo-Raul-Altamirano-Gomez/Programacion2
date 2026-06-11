//
// Created by hrodic on 4/06/2026.
//

#include "Restaurante.h"

Restaurante::Restaurante() {
    this->cantidad_comandas=-1;
}

void Restaurante::cargar_comandas() {
    this->leer_archivo_comandas();
    this->leer_archivo_atenciones();
}

void Restaurante::leer_archivo_comandas() {
    ifstream archComandas("ArchivosDeDatos/comandas.csv",ios::in);
    int id_comanda,id_comanda_anterior=0;
    while (archComandas>>id_comanda) {
        if (id_comanda!=id_comanda_anterior) this->cantidad_comandas++;
        archComandas.ignore();
        this->comandas[this->cantidad_comandas].set_id(id_comanda);
        archComandas>>this->comandas[this->cantidad_comandas];
        id_comanda_anterior=id_comanda;
    }
}

void Restaurante::leer_archivo_atenciones() {
    ifstream archAtenciones("ArchivosDeDatos/atenciones.csv");
    int id_comanda,horas_atencion,min_atencion,horas_servicio,min_servicio,hora_atencion,hora_servicio;
    char car;
    while (archAtenciones>>id_comanda) {
        int posComanda=this->buscar_comanda(id_comanda);
        if (posComanda>=0) {
            archAtenciones>>car>>horas_atencion>>car>>min_atencion>>car>>horas_servicio>>car>>min_servicio;
            hora_atencion=horas_atencion*60+min_atencion;
            hora_servicio=horas_servicio*60+min_servicio;
            this->comandas[posComanda].completar(hora_atencion,hora_servicio);
        } else archAtenciones.ignore(50,'\n');
    }
}

int Restaurante::buscar_comanda(int id_comanda) const {
    for (int i=0;i<this->cantidad_comandas;i++) {
        if (this->comandas[i].get_id()==id_comanda) return i;
    }
    return -1;
}

void Restaurante::actualizar_comandas() {
    for (int i=0;i<this->cantidad_comandas;i++) {
        this->comandas[i].actualizar();
    }
}

void Restaurante::imprimir_comandas() const {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt");
    archReporte<<"Cantidad de comandas: "<<this->cantidad_comandas<<endl;
    for (int i=0;i<this->cantidad_comandas;i++) archReporte<<this->comandas[i]<<endl;
}
