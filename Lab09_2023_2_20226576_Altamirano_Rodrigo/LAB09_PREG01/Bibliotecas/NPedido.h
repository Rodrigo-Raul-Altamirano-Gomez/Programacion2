//
// Created by hrodic on 22/06/2026.
//

#ifndef LAB09_PREG01_NPEDIDO_H
#define LAB09_PREG01_NPEDIDO_H
#include <string>
#include <fstream>

class NPedido {
    std::string codigo;
    int cantidad;
    double peso;
public:
    NPedido();
    void imprimir(std::ofstream&) const;
};


#endif //LAB09_PREG01_NPEDIDO_H
