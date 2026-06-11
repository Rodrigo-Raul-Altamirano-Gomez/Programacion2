//
// Created by hrodic on 4/06/2026.
//

#ifndef PREG01_RESTAURANTE_H
#define PREG01_RESTAURANTE_H

#include <fstream>
#include "Comanda.h"
using namespace std;

class Restaurante {
    Comanda comandas[100];
    int cantidad_comandas;
    void leer_archivo_comandas();
    void leer_archivo_atenciones();
    int buscar_comanda(int) const;
public:
    Restaurante();
    void cargar_comandas();
    void imprimir_comandas();
};


#endif //PREG01_RESTAURANTE_H
