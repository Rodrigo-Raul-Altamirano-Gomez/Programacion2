//
// Created by hrodic on 9/05/2026.
//
#include "Paciente.h"
#include "Cita.h"

Cita::Cita() {
    this->dni=0;
    this->tarifa=0;
}

ifstream& operator>>(ifstream& archCitas,Cita& cita) {
    int dni,codigo,dia,mes,anio,fecha;
    if (archCitas>>dni) {
        char car;
        archCitas>>car>>codigo>>car>>dia>>car>>mes>>car>>anio;
        fecha=dia+mes*100+anio*10000;
        cita.setDni(dni);
        cita.setCodigo(codigo);
        cita.setFecha(fecha);
    }
    return archCitas;
}

void Cita::setDni(int dni) {
    this->dni=dni;
}

void Cita::setCodigo(int codigo) {
    this->codigo=codigo;
}

void Cita::setFecha(int fecha) {
    this->fecha=fecha;
}

int Cita::getDni() const {
    return this->dni;
}

Cita &Cita::operator<=(const Medico *arrMedicos) {
    for (int i=0;arrMedicos[i].getCodigo()>0;i++) {
        if (this->codigo==arrMedicos[i].getCodigo()) {
            this->tarifa=arrMedicos[i].getTarifa();
            break;
        }
    }
    return *this;
}

double Cita::getTarifa() const {
    return this->tarifa;
}

int Cita::getCodigo() const {
    return this->codigo;
}

int Cita::getFecha() const {
    return this->fecha;
}

int Cita::buscarPaciente(const Paciente *arrPacientes) const {
    for (int i=0;arrPacientes[i].getNombre();i++) {
        if (this->dni==arrPacientes[i].getDni()) return i;
    }
    return -1;
}

