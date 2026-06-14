//
// Created by hrodic on 11/06/2026.
//

#include "Tesoreria.h"

#include <iomanip>

void Tesoreria::cargarescalas() {
    ifstream archEscalas("ArchivosDeDatos/escalas.csv",ios::in);
    int numEscala,cantEscalas=0;
    char car;
    double precioEscala;
    while (archEscalas>>numEscala) {
        archEscalas>>car>>precioEscala;
        this->lescala[cantEscalas].setCodigo(numEscala);
        this->lescala[cantEscalas].setPrecio(precioEscala);
        cantEscalas++;
    }
}

void Tesoreria::cargaalumnos() {
    ifstream archAlumnos("ArchivosDeDatos/Alumnos.csv",ios::in);
    char tipoAlumno;
    int cantAlumnos=0;
    while (archAlumnos>>tipoAlumno) {
        archAlumnos.ignore();
        this->lboleta[cantAlumnos].leer(archAlumnos,tipoAlumno);
        cantAlumnos++;
    }
}

void Tesoreria::imprimeboleta() {
    ofstream archReporte("ArchivosDeReporte/ReportePrueba.txt",ios::out);
    archReporte<<fixed<<setprecision(2);
    archReporte<<left<<setw(12)<<"Codigo"<<setw(45)<<"Nombre"<<setw(12)<<"Escala"<<setw(12)<<"Cred.";
    archReporte<<setw(12)<<"Dato"<<"Total"<<endl;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    for (int i=0;this->lboleta[i].existe();i++) this->lboleta[i].imprimir(archReporte);
}
