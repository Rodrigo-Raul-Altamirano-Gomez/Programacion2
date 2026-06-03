//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESTANTE_H
#define LAB07_BIBLIOTECA_HERENCIA_ESTANTE_H

#include <fstream>
#include "Espacio.h"
#include "Enciclopedia.h"
#include "Novela.h"
using namespace std;

class Estante {
    char* codigo;
    int anchura;
    int altura;
    Espacio* espacios;
    double pesoSoportado;
    double pesoActual;
public:
    Estante();
    void leerEstante(ifstream&);
    char* leerCadena(ifstream&);
    const char* getCodigo() const;
    int getAltura() const;
    int getAnchura() const;
    double getPesoMaximo() const;
    double getPesoActual() const;
    void insertarEnciclopedia(const Enciclopedia&);
    void insertarNovela(const Novela&);
    void imprimirEspacios(ofstream&) const;
    ~Estante();
};


#endif //LAB07_BIBLIOTECA_HERENCIA_ESTANTE_H
