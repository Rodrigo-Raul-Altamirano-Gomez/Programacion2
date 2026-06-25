//
// Created by hrodic on 23/06/2026.
//

#ifndef PREG01_LAB09_ORACION_H
#define PREG01_LAB09_ORACION_H
#include <vector>
#include <map>
#include "Palabra.h"

class Oracion {
    std::vector<Palabra> palabras;
    int polaridad_total;
    int cantidad_palabras;
public:
    Oracion();
    int getPolaridadTotal() const;
    void tokenizar(const std::string&,const std::map<std::string,int>&);
    bool operator<(const Oracion&) const;
    void imprimir(std::ofstream&) const;
};


#endif //PREG01_LAB09_ORACION_H
