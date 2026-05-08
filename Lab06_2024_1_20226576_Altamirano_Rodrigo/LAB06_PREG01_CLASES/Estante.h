//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB06_PREG01_CLASES_ESTANTE_H
#define LAB06_PREG01_CLASES_ESTANTE_H

#include "Libro.h"
#include "Espacio.h"
#include "Espacio.h"

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
    int getEspaciosSobrantes();
    void actualizarEspacios(int,const Libro&);
};


#endif //LAB06_PREG01_CLASES_ESTANTE_H
