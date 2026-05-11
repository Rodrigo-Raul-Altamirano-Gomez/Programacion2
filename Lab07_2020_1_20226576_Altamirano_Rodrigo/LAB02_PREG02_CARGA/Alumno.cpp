//
// Created by hrodic on 10/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Alumno.h"

Alumno::Alumno() {
    this->nombre=nullptr;
    this->lcurso=nullptr;
    this->numcur=0;
}

Alumno &Alumno::operator+(const Acurso &cursoAlumno) {
    if (this->numcur==0) this->lcurso=new Curso[1](cursoAlumno.getCurso());
    else {
        Curso* aux=new Curso[this->numcur+1];
        for (int i=0;i<this->numcur;i++) aux[i].asignar(this->lcurso[i]);
        aux[this->numcur].asignar(cursoAlumno.getCurso());
        delete[] this->lcurso;
        this->lcurso=aux;
    }
    this->numcur++;
    return *this;
}

Alumno &Alumno::operator*(const Acurso & cursoAlumno) {
    for (int i=0;i<this->numcur;i++) {
        if (this->lcurso[i].compare(cursoAlumno.getCurso())) {
            this->lcurso[i]=cursoAlumno.getCurso();
            break;
        }
    }
    return *this;
}

Alumno &Alumno::operator-(const Acurso &cursoAlumno) {
    int posCurso=cursoAlumno.buscarCurso(this->lcurso,this->numcur);
    if (posCurso>=0) {
        for (int i=posCurso;i<this->numcur-1;i++) {
            this->lcurso[i]=this->lcurso[i+1];
        }
        delete &(this->lcurso[this->numcur-1]);
        this->numcur--;
    }
    return *this;
}

double Alumno::operator/(int ciclo) const {
    double promedio,sumNotasPonderadas=0,sumCreditos=0;
    for (int i=0;i<this->numcur;i++) {
        if (this->lcurso[i].getCiclo()==ciclo) {
            sumNotasPonderadas+=this->lcurso[i].getNota()*this->lcurso[i].getCredito();
            sumCreditos+=this->lcurso[i].getCredito();
        }
    }
    promedio=sumNotasPonderadas/sumCreditos;
    return promedio;
}

double Alumno::operator--() const {
    double sumCreditos=0;
    for (int i=0;i<this->numcur;i++) {
        sumCreditos+=this->lcurso[i].getCredito();
    }
    return sumCreditos;
}

double Alumno::operator++() const {
    double sumCreditosAprob=0;
    for (int i=0;i<this->numcur;i++) {
        if (this->lcurso[i].getNota()>=11) {
            sumCreditosAprob+=this->lcurso[i].getCredito();
        }
    }
    return sumCreditosAprob;
}

ifstream& operator>>(ifstream& archAlumnos,Alumno& alumno) {
    char tipo,nombre[200];
    if (archAlumnos>>tipo) {
        int codigo;
        archAlumnos>>codigo>>nombre;
        archAlumnos.ignore(100,'\n');
        alumno.setCodigo(codigo);
        alumno.setTipo(tipo);
        alumno.setNombre(nombre);
    }
    return archAlumnos;
}

void Alumno::setCodigo(int codigo) {
    this->codigo=codigo;
}

void Alumno::setTipo(char tipo) {
    this->tipo=tipo;
}

void Alumno::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

ofstream& operator<<(ofstream& archReporte,const Alumno& alumno) {
    archReporte<<"Nombre: "<<alumno.getNombre()<<endl;
    archReporte<<"Codigo: "<<alumno.getCodigo()<<endl;
    archReporte<<setfill('=')<<setw(50)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(8)<<" "<<left<<setw(30)<<"CICLO"<<"PROMEDIO"<<endl<<right;
    alumno.imprimirCursos(archReporte);
    archReporte<<"Creditos Cursados: "<<setw(6)<<--alumno<<endl;
    archReporte<<"Creditos Aprobados: "<<setw(4)<<++alumno<<endl;
    return archReporte;
}

const char *Alumno::getNombre() const {
    return this->nombre;
}

int Alumno::getCodigo() const {
    return this->codigo;
}

void Alumno::imprimirCursos(ofstream &archReporte) const {
    int anio=2012,semestre=0,i=0;
    for (int cont=0;anio<2024;cont++) {
        if (semestre==3) {
            semestre=0;
            anio++;
        }
        int ciclo=anio*10+semestre;
        double promedio=*this/ciclo;
        if (promedio>0) {
            archReporte<<setw(4)<<i+1<<")"<<setw(7)<<anio<<"-"<<semestre<<setw(32)<<promedio<<endl;
            i++;
        }
        semestre++;
    }
}

Alumno &Alumno::operator=(const Alumno &alumno) {
    if (this!=&alumno) {
        this->codigo=alumno.codigo;
        setNombre(alumno.nombre);
        this->tipo=alumno.tipo;
    }
    return *this;
}

Alumno::~Alumno() {
    delete[] this->lcurso;
    delete[] this->nombre;
    this->lcurso=nullptr;
    this->nombre=nullptr;
}
