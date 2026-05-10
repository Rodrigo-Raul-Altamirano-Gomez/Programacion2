//
// Created by hrodic on 10/05/2026.
//
#include <cstring>
#include "Usuario.h"

Usuario::Usuario() {
    this->nombre=nullptr;
    this->libPrest=nullptr;
    this->numLibPrest=0;
    this->condicion=1;
}

ifstream& operator>>(ifstream& archUsuarios,Usuario& usuario) {
    int carne;
    if (archUsuarios>>carne) {
        char car,tipo,nombre[200];
        archUsuarios>>tipo>>car;
        archUsuarios.getline(nombre,200,'\n');
        usuario.setCarne(carne);
        usuario.setTipo(tipo);
        usuario.setNombre(nombre);
    }
    return archUsuarios;
}

void Usuario::setCarne(int carne) {
    this->carne=carne;
}

void Usuario::setTipo(char tipo) {
    this->tipo=tipo;
}

void Usuario::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

Usuario &Usuario::operator+=(const LibroPrestado &libroPrestado) {
    if (this->numLibPrest==0) this->libPrest=new LibroPrestado[1];
    else {
        LibroPrestado* aux=new LibroPrestado[this->numLibPrest+1];
        for (int i=0;i<this->numLibPrest;i++) aux[i]=this->libPrest[i];
        delete[] this->libPrest;
        this->libPrest=aux;
    }
    this->libPrest[this->numLibPrest]=libroPrestado;
    this->numLibPrest++;
    return *this;
}

Usuario &Usuario::operator*(int fecha) {
    for (int i=0;i<this->numLibPrest;i++) {
        int fechaRetiro=this->libPrest[i].getFechaRetiro();
        int diaRetiro,mesRetiro,anioRetiro,diaFecha,mesFecha,anioFecha,res;
        anioRetiro=fechaRetiro/10000,res=fechaRetiro%10000,mesRetiro=res/100,diaRetiro=res%100;
        anioFecha=fecha/10000,res=fecha%10000,mesFecha=res/100,diaFecha=res%100;
        int diasRetiro=diaRetiro+mesRetiro*30+anioRetiro*365,diasFecha=diaFecha+mesFecha*30+anioFecha*365;
        int diasPrestamo=diasFecha-diasRetiro;
        int deuda=(diasPrestamo>15 and this->tipo=='D')+(diasPrestamo>10 and this->tipo=='E')
        +(diasPrestamo>7 and this->tipo=='A');
        this->libPrest[i].setDeuda(deuda);
        if (deuda) this->condicion=0;
    }
    return *this;
}

ofstream& operator<<(ofstream& archReporte,const Usuario& usuario) {
    archReporte<<"Carne: "<<usuario.getCarne()<<endl;
    archReporte<<usuario.getNombre()<<endl;
    if (usuario.getTipo()=='E') archReporte<<"Estudiante"<<endl;
    else if(usuario.getTipo()=='D') archReporte<<"Docente"<<endl;
    else archReporte<<"Administrativo"<<endl;
    usuario.getCondicion()==1 ? archReporte<<"HABILITADO"<<endl:archReporte<<"INHABILITADO"<<endl;
    const LibroPrestado* librosPrestados=usuario.getLibros();
    for (int i=0;i<usuario.getNumLibros();i++) archReporte<<librosPrestados[i];
    return archReporte;
}

int Usuario::getCarne() const {
    return this->carne;
}

const char *Usuario::getNombre() const {
    return this->nombre;
}

char Usuario::getTipo() const {
    return this->tipo;
}

int Usuario::getCondicion() const {
    return this->condicion;
}

int Usuario::getNumLibros() const {
    return this->numLibPrest;
}

const LibroPrestado *Usuario::getLibros() const {
    return this->libPrest;
}

Usuario &Usuario::operator=(const Usuario &usuario) {
    if (this!=&usuario) {
        this->carne=usuario.carne;
        this->tipo=usuario.tipo;
        setNombre(usuario.nombre);
    }
    return *this;
}

Usuario::~Usuario() {
    delete[] this->libPrest;
    delete[] this->nombre;
    this->libPrest=nullptr;
    this->nombre=nullptr;
}
