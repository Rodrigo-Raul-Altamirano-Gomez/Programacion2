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
    void tokenizar(const std::string&,const std::map<std::string,int>&);
    int getPolardadTotal() const;
};


#endif //PREG01_LAB09_ORACION_H
