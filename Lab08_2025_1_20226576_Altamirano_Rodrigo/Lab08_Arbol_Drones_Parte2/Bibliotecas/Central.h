//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_CENTRAL_H
#define LAB08_ARBOL_DRONES_PARTE1_CENTRAL_H
#include "Arbol.h"
#include <fstream>
using namespace std;

class Central {
    Arbol ADrones;
public:
    void carga();
    void actualiza();
    void muestra() const;
};


#endif //LAB08_ARBOL_DRONES_PARTE1_CENTRAL_H
