//
// Created by hrodic on 1/06/2026.
//

#ifndef STREAMERS_HERENCIA_METRICA_H
#define STREAMERS_HERENCIA_METRICA_H

#include <fstream>
using namespace std;

class Metrica {
    int id;
    char* descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
public:
    Metrica();
    Metrica(const Metrica&);
    Metrica& operator=(const Metrica&);
    void setDescripcion(const char*);
    char* getDescripcion() const;
    bool getEstado() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Metrica();
};


#endif //STREAMERS_HERENCIA_METRICA_H
