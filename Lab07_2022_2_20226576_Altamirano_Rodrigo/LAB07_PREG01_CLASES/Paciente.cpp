//
// Created by hrodic on 9/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Paciente.h"

Paciente::Paciente() {
    this->nombre=nullptr;
    this->totalgastado=0;
}

ifstream& operator>>(ifstream& archPacientes,Paciente& paciente) {
    int dni,telefono;
    if (archPacientes>>dni) {
        char buffer[200];
        archPacientes.ignore();
        archPacientes.getline(buffer,200,',');
        archPacientes>>telefono;
        paciente.setDni(dni);
        paciente.setNombre(buffer);
        paciente.setTelefono(telefono);
    }
    return archPacientes;
}

void Paciente::setDni(int dni) {
    this->dni=dni;
}

void Paciente::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Paciente::setTelefono(int telefono) {
    this->telefono=telefono;
}

Paciente &Paciente::operator+=(const Cita &cita) {
    int cantCitas=0;
    for (int i=0;this->lcitas[i].getDni()>0;i++) cantCitas++;
    this->lcitas[cantCitas]=cita;
    return *this;
}

Paciente& Paciente::operator++(int) {
    for (int i=0;this->lcitas[i].getDni()>0;i++) {
        this->totalgastado+=this->lcitas[i].getTarifa();
    }
    return *this;
}

ofstream& operator<<(ofstream& archReporte,const Paciente& paciente) {
    archReporte<<fixed<<setprecision(2);
    archReporte<<setw(4)<<" "<<left<<setw(20)<<"DNI"<<setw(20)<<"NOMBRE"<<"TELEFONO"<<endl;
    archReporte<<right<<setw(10)<<paciente.getDni()<<setw(10)<<" "<<left<<setw(20)<<paciente.getNombre();
    archReporte<<right<<setw(12)<<paciente.getTelefono()<<endl;
    archReporte<<"RELACION DE CITAS"<<endl;
    archReporte<<left<<setw(5)<<"No."<<setw(15)<<"FECHA"<<setw(25)<<"CODIGO DEL MEDICO"<<"TARIFA"<<right<<endl;
    paciente.imprimirCitas(archReporte);
    archReporte<<"MONTO TOTAL GASTADO: "<<paciente.getTotal()<<endl;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    return archReporte;
}

int Paciente::getDni() const {
    return this->dni;
}

const char *Paciente::getNombre() const {
    return this->nombre;
}

int Paciente::getTelefono() const {
    return this->telefono;
}

void Paciente::imprimirCitas(ofstream &archReporte) const {
    int dia,mes,anio,res;
    for (int i=0;this->lcitas[i].getDni()>0;i++) {
        anio=this->lcitas[i].getFecha()/10000;
        res=this->lcitas[i].getFecha()%10000;
        mes=res/100;
        dia=res%100;
        archReporte<<i+1<<")"<<setw(3)<<" "<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<anio;
        archReporte<<setfill(' ')<<setw(17)<<this->lcitas[i].getCodigo();
        archReporte<<setw(19)<<this->lcitas[i].getTarifa()<<endl;
    }
}

double Paciente::getTotal() const {
    return this->totalgastado;
}

Paciente::~Paciente() {
    delete[] this->nombre;
}
