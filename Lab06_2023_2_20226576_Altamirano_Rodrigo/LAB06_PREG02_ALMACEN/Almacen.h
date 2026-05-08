//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB06_PREG01_CLASES_ALMACEN_H
#define LAB06_PREG01_CLASES_ALMACEN_H

#include "Cliente.h"
#include "Producto.h"

class Almacen {
    Cliente arreglo_clientes[150];
    int cantidad_clientes;
    Producto arreglo_productos[180];
    int cantidad_productos;
public:
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    void mostrar_datos();
};


#endif //LAB06_PREG01_CLASES_ALMACEN_H
