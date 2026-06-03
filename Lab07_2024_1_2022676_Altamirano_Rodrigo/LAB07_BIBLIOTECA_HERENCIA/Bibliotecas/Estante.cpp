//
// Created by hrodic on 25/05/2026.
//
#include <cstring>
#include "Estante.h"

Estante::Estante() {
    this->codigo=nullptr;
    this->espacios=nullptr;
    this->pesoActual=0;
}

void Estante::leerEstante(ifstream &archEstantes) {
    char car;
    this->codigo=this->leerCadena(archEstantes);
    archEstantes>>this->anchura>>car>>this->altura>>car>>this->pesoSoportado;
    this->espacios=new Espacio[this->anchura*this->altura];
    for (int i=0;i<this->altura*this->anchura;i++) {
        this->espacios[i].setPosX(i%this->anchura);
        this->espacios[i].setPosY(i/this->anchura);
    }
}

char *Estante::leerCadena(ifstream &archEstantes) {
    char buffer[100],*cadenaExacta;
    archEstantes.getline(buffer,100,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

const char *Estante::getCodigo() const {
    return this->codigo;
}

int Estante::getAltura() const {
    return this->altura;
}

int Estante::getAnchura() const {
    return this->anchura;
}

double Estante::getPesoMaximo() const {
    return this->pesoSoportado;
}

double Estante::getPesoActual() const {
    return  this->pesoActual;
}

void Estante::insertarEnciclopedia(const Enciclopedia &enciclopedia) {
    int i=this->anchura,j=this->altura;
    int cont=0;
    this->pesoActual+=enciclopedia.getPeso();
    while (i*j>0) {
        if (cont==enciclopedia.getAltura()) break;
        if (this->espacios[i*j-1].getContenido()=='N') {
            for (int k=0;k<enciclopedia.getAnchura();k++) this->espacios[i*j-(k+1)].setContenido('S');
            cont++;
        }
        j--;
    }
}

void Estante::insertarNovela(const Novela &novela) {
    int i=this->anchura,j=this->altura;
    int cont=0;
    this->pesoActual+=novela.getPeso();
    for (int k=i*(j-1);j<i*j;k++) {
        if (cont==novela.getAnchura()) break;
        if (this->espacios[k].getContenido()=='N') {
            for (int l=0;l<novela.getAltura();l++) this->espacios[k-l*i].setContenido('S');
            cont++;
        }
    }
}

void Estante::imprimirEspacios(ofstream &archReporte) const {
    for (int i=0;i<this->anchura*this->altura;i++) {
        if (i%this->anchura==0) archReporte<<endl;
        if (this->espacios[i].getContenido()=='S') archReporte<<"[ * ] ";
        else archReporte<<"[   ] ";

    }
}

Estante::~Estante() {
    delete[] this->codigo;
    delete[] this->espacios;
}
