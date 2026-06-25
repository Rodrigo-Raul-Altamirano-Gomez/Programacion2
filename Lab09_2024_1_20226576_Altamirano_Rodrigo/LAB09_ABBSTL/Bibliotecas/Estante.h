//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_NESTANTE_H
#define LAB09_ABBSTL_NESTANTE_H
#include <vector>
#include <fstream>
#include "NLibro.h"

class Estante {
    int id;
    double capacidad;
    double disponible;
    std::vector<NLibro> vlibros;
public:
    void setDisponible(double);
    double getDisponible() const;
    bool leer(std::ifstream&);
    void vaciar();
    void cargar(NLibro);
    bool operator<=(const Estante&) const;
    void imprimir(std::ofstream&);
};

std::ofstream& operator<<(std::ofstream&,Estante);

#endif //LAB09_ABBSTL_NESTANTE_H
