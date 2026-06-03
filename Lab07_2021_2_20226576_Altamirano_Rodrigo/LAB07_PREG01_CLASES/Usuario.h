//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB07_PREG01_CLASES_USUARIO_H
#define LAB07_PREG01_CLASES_USUARIO_H

#include "LibroPrestado.h"

class Usuario {
    int carne;
    char tipo;
    char* nombre;
    LibroPrestado* libPrest;
    int numLibPrest;
    int condicion;
public:
    Usuario();
    void setCarne(int);
    void setTipo(char);
    void setNombre(const char*);
    Usuario& operator+=(const LibroPrestado&);
    Usuario& operator*(int);
    int getCarne() const;
    const char* getNombre() const;
    char getTipo() const;
    int getCondicion() const;
    int getNumLibros() const;
    const LibroPrestado* getLibros() const;
    ~Usuario();
};

ifstream& operator>>(ifstream&,Usuario&);
ofstream& operator<<(ofstream&,const Usuario&);

#endif //LAB07_PREG01_CLASES_USUARIO_H
