//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB06_PREG01_CLASES_LIBRO_H
#define LAB06_PREG01_CLASES_LIBRO_H

#include <fstream>
using namespace std;

class Libro {
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    void setDatosLibro(const char*,const char*,int,int);
    void setEstado(bool);
    int getAncho() const;
    int getAlto() const;
    const char* getCodigo() const;
    const char* getNombre() const;
};

ifstream& operator>>(ifstream&,Libro&);
ofstream& operator<<(ofstream&,const Libro&);

#endif //LAB06_PREG01_CLASES_LIBRO_H
