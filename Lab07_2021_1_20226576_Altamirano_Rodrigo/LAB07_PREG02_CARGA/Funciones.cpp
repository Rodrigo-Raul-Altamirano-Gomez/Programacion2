//
// Created by hrodic on 10/05/2026.
//
#include <iostream>
#include "Funciones.h"

void cargarConductores(Conductor*& arrConductores,int& cantConductores) {
    ifstream archConductores("Conductores.csv",ios::in);
    Conductor bufferConductores[120]{};
    cantConductores=0;
    while (archConductores>>bufferConductores[cantConductores]) cantConductores++;
    arrConductores=new Conductor[cantConductores]{};
    for (int i=0;i<cantConductores;i++) arrConductores[i]=bufferConductores[i];
}

void procesarFaltas(Conductor* arrConductores,int cantConductores) {
    ifstream archFaltas("RegistroDeFaltas.csv",ios::in);
    Falta falta;
    while (archFaltas>>falta) {
        for (int i=0;i<cantConductores;i++) {
            if (arrConductores[i].getLicencia()==falta.getLicencia()) {
                arrConductores[i]+falta;
                break;
            }
        }
    }
}

void completarInfracciones(Conductor* arrConductores,int cantConductores) {
    ifstream archInfracciones("Infracciones.csv",ios::in);
    Infraccion infraccion;
    while (archInfracciones>>infraccion) {
        for (int i=0;i<cantConductores;i++) {
            arrConductores[i]+infraccion;
        }
    }
}

void calcularTotales(Conductor* arrConductores,int cantConductores) {
    for (int i=0;i<cantConductores;i++) {
        arrConductores[i]++;
    }
}

void emitirReporte(const Conductor* arrConductores,int cantConductores,const char* nombreArchReporte) {
    ofstream archReporte(nombreArchReporte,ios::out);
    for (int i=0;i<cantConductores;i++) {
        archReporte<<arrConductores[i];
    }
}

void aplicarAmnistia(Conductor* arrConductores,int cantConductores) {
    int dia,mes,anio,fechaAmnistia;
    char car;
    cout<<"Ingrese la fecha: ";
    cin>>dia>>car>>mes>>car>>anio;
    fechaAmnistia=dia+mes*100+anio*10000;
    for (int i=0;i<cantConductores;i++) {
        arrConductores[i]*fechaAmnistia;
        arrConductores[i]++;
    }
}