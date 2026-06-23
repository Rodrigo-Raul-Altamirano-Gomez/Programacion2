//
// Created by hrodic on 21/06/2026.
//
using namespace std;
#include "Reserva.h"

void Reserva::carga(std::string nombreArchivoAulas, std::string nombreArchivoMiembros) {
    ifstream archAulas(nombreArchivoAulas,ios::in);
    ifstream archMiembros(nombreArchivoMiembros,ios::in);
    Aula aula;
    Persona* persona;
    char tipoPersona;
    while (archAulas>>aula) this->vAula.push_back(aula);
    while (archMiembros>>tipoPersona) {
        archMiembros.ignore();
        if (tipoPersona=='A') persona=new Alumno;
        else persona=new Profesor;
        archMiembros>>persona;
        if (tipoPersona=='A') this->alumnos.encola(persona);
        else this->profesores.encola(persona);
    }
}

void Reserva::asigna(int capacidad) {
    for (vector<Aula>::iterator iterador=this->vAula.begin();iterador!=this->vAula.end();iterador++) {
        Persona* persona;
        if (iterador->getCapacidad()<=capacidad) {
            if (not this->alumnos.esColaVacia()) {
                persona=this->alumnos.desencola();
                iterador->setTipo('A');
            } else continue;
        } else {
            if (not this->profesores.esColaVacia()) {
                persona=this->profesores.desencola();
                iterador->setTipo('P');
            } else continue;;
        }
        iterador->setCodigo(persona->getCodigo());
        iterador->setNombre(persona->getNombre());
        delete persona;
    }
}

void Reserva::imprime(std::string nombreArchivo) const {
    ofstream archReporte(nombreArchivo,ios::out);
    archReporte<<setw(30)<<"Reservas Asignadas"<<endl;
    for (vector<Aula>::const_iterator iterador=this->vAula.begin();iterador!=this->vAula.end();iterador++) {
        archReporte<<*iterador;
        archReporte<<setfill('-')<<setw(50)<<" "<<setfill(' ')<<endl;
    }
}
