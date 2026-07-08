//
// Created by hrodic on 26/06/2026.
//

#ifndef LABORATORIO09_STL_ETIQUETA_H
#define LABORATORIO09_STL_ETIQUETA_H
#include <string>
#include <fstream>

class Etiqueta {
    std::string codigo;
    std::string nombre;
public:
    Etiqueta()= default;
    Etiqueta(const Etiqueta&) = default;
    Etiqueta& operator=(const Etiqueta&) = default;
    std::string getCodigo() const;
    std::string getNombre() const;
    void leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    ~Etiqueta() = default;
};

std::ifstream& operator>>(std::ifstream&,Etiqueta&);
std::ofstream& operator<<(std::ofstream&,const Etiqueta&);

#endif //LABORATORIO09_STL_ETIQUETA_H
