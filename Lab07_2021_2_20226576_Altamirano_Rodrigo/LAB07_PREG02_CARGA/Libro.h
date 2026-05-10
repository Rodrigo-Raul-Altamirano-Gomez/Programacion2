//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB07_PREG01_CLASES_LIBRO_H
#define LAB07_PREG01_CLASES_LIBRO_H

#include "LibroPrestado.h"

class Libro {
    char* codigo;
    char* titulo;
    char* autor;
    int stock;
    double precio;
    int prestados;
    int cantEst;
    int cantDoc;
    int cantAdm;
public:
    Libro();
    void setCodigo(const char*);
    void setTitulo(const char*);
    void setAutor(const char*);
    void setStock(int);
    void setPrecio(double);
    Libro& operator+=(const LibroPrestado&);
    const char* getCodigo() const;
    const char* getTitulo() const;
    const char* getAutor() const;
    int getStock() const;
    int getNumEst() const;
    int getNumDoc() const;
    int getNumAdm() const;
    int getNumPrestamos() const;
    Libro& operator=(const Libro&);
    double getPrecio() const;
    ~Libro();
};

ifstream& operator>>(ifstream&,Libro&);
ofstream& operator<<(ofstream&,const Libro&);

#endif //LAB07_PREG01_CLASES_LIBRO_H
