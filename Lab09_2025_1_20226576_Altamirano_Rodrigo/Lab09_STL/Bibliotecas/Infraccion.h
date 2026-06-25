//
// Created by hrodic on 25/06/2026.
//

#ifndef LAB09_STL_INFRACCION_H
#define LAB09_STL_INFRACCION_H
#include <string>
#include <fstream>

class Infraccion {
     std::string codigo;
     double multa;
     std::string gravedad;
     std::string descripcion;
public:
     Infraccion() = default;
     Infraccion(const std::string&);
     Infraccion(const Infraccion&) = default;
     std::string getCodigo() const;
     double getMulta() const;
     std::string getGravedad() const;
     std::string getDescripcion() const;
     Infraccion& operator=(const Infraccion&) = default;
     bool operator<(const Infraccion&) const;
     bool leer(std::ifstream&);
     void imprimir(std::ofstream&) const;
     bool operator==(const Infraccion&) const;
     ~Infraccion() = default;
};

std::ifstream& operator>> (std::ifstream&, Infraccion&);
std::ofstream& operator<< (std::ofstream&, const Infraccion&);

#endif //LAB09_STL_INFRACCION_H
