//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB06_PREG01_CLASES_ESTANTE_H
#define LAB06_PREG01_CLASES_ESTANTE_H

#include "Libro.h"
#include "Espacio.h"
#include <fstream>
using namespace std;

class Estante {
    char* codigo;
    int anchura;
    int altura;
    Libro libros[20];
    Espacio* espacios;
    int cantidad_libros;
public:
    void setDatosEstante(const char*,int,int);
    void setCantidadLibros(int);
    void inicializarEspacios();
    bool operator+=(Libro&);
    int getEspaciosSobrantes() const;
    void actualizarEspacios(int,const Libro&);
    const char* getCodigo() const;
    int getCantLibros() const;
    int getAnchura() const;
    int getAltura() const;
    void imprimirEspacios(ofstream&) const;
    void imprimirLibros(ofstream&) const;
};

ifstream& operator>>(ifstream&,Estante&);
ofstream& operator<<(ofstream&,const Estante&);

#endif //LAB06_PREG01_CLASES_ESTANTE_H
