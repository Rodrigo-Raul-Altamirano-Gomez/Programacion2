//
// Created by hrodic on 25/06/2026.
//

#ifndef LAB09_STL_VEHICULO_H
#define LAB09_STL_VEHICULO_H
#include <string>
#include <fstream>

class Vehiculo {
    std::string placa;
    std::string marca;
    std::string modelo;
public:
    Vehiculo() = default;
    Vehiculo(const Vehiculo&) = default;
    std::string getPlaca() const;
    std::string getMarca() const;
    std::string getModelo() const;
    Vehiculo& operator=(const Vehiculo&) = default;
    void leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    ~Vehiculo() = default;
};

std::ifstream& operator>> (std::ifstream&, Vehiculo&);
std::ofstream& operator<< (std::ofstream&, const Vehiculo&);

#endif //LAB09_STL_VEHICULO_H
