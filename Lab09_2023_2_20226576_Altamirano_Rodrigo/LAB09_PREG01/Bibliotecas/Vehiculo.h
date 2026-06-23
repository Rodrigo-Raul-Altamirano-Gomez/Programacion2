//
// Created by hrodic on 22/06/2026.
//

#ifndef LAB09_PREG01_VEHICULO_H
#define LAB09_PREG01_VEHICULO_H
#include <string>
#include <fstream>

class Vehiculo {
    int cliente;
    std::string placa;
    double maxcarga;
    double actcarga;
public:
    Vehiculo();
    virtual void leer(std::ifstream&);
    virtual Vehiculo* clonar() const = 0;
    virtual void imprimir(std::ofstream&);
    virtual ~Vehiculo() = default;
};


#endif //LAB09_PREG01_VEHICULO_H
