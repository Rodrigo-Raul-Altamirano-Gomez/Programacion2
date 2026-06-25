//
// Created by hrodic on 25/06/2026.
//

#ifndef LAB09_STL_MINISTERIODETRANSPORTE_H
#define LAB09_STL_MINISTERIODETRANSPORTE_H
#include "Infraccion.h"
#include "Empresa.h"
#include <list>
#include <string>
#include <fstream>

class MinisterioDeTransporte {
    std::list<Infraccion> tablaInfracciones;
    std::list<Empresa> listaEmpresas;
    std::list<Empresa>::iterator buscarEmpresaPorPlaca(const std::string&);
public:
    void cargaDeInfracciones(const std::string&);
    void cargaEmpresas(const std::string&);
    void cargaVehiculos(const std::string&);
    void cargaInfraccionesCometidas(const std::string&);
    void reporteDeEmpresasConInfracciones(const std::string&) const;
    void eliminaInfraccionesPagadas();
    static void rellenarLinea(char,std::ofstream&);
};


#endif //LAB09_STL_MINISTERIODETRANSPORTE_H
