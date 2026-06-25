//
// Created by hrodic on 25/06/2026.
//

#ifndef LAB09_STL_EMPRESA_H
#define LAB09_STL_EMPRESA_H
#include <string>
#include <map>
#include "Vehiculo.h"
#include "Multa.h"
#include <vector>

class Empresa {
    int dni;
    std::string nombre;
    std::string distrito;
    std::map<std::string,Vehiculo> vehiculos;
    std::vector<Multa> multasRecibidas;
public:
    Empresa() = default;
    Empresa(int);
    int getDni() const;
    std::string getNombre() const;
    std::string getDistrito() const;
    std::map<std::string,Vehiculo> getVehiculos() const;
    std::vector<Multa> getMultasRecibidas() const;
    bool leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    bool operator<(const Empresa&) const;
    bool operator==(const Empresa&) const;
    void añadirVehiculo(const Vehiculo&);
    void anadirMulta(const Multa&);
    void eliminarInfraccionesPagadas();
    ~Empresa() = default;
};


#endif //LAB09_STL_EMPRESA_H
