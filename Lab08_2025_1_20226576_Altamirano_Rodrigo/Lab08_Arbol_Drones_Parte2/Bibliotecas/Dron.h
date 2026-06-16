//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRON_H
#define LAB08_ARBOL_DRONES_PARTE1_DRON_H
#include <fstream>
using namespace std;

class Dron {
    char* id;
    char* ubicacion;
    int capacidad;
public:
    Dron();
    void setID(const char*);
    void setUbicacion(const char*);
    void getID(char*) const;
    virtual void leer(ifstream&);
    virtual char getTipo() const = 0;
    virtual void actualizar() = 0;
    virtual void imprimir(ofstream&) const;
    virtual ~Dron();
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRON_H
