//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_LIBRO_H
#define LAB07_BIBLIOTECA_HERENCIA_LIBRO_H

#include <fstream>
using namespace std;

class Libro {
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;
public:
    Libro();
    Libro(const Libro&);
    void leerLibro(ifstream&);
    char* leerCadena(ifstream&) const;
    int getAltura() const;
    int getAnchura() const;
    void setColocado(bool);
    void setPeso(double);
    Libro& operator=(const Libro&);
    char* copiarCadena(const char*) const;
    void imprimirLibro(ofstream&) const;
    ~Libro();
};


#endif //LAB07_BIBLIOTECA_HERENCIA_LIBRO_H
