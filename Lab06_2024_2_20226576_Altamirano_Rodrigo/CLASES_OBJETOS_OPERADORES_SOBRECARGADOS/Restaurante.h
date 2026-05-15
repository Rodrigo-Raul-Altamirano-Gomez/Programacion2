//
// Created by hrodic on 14/05/2026.
//

#ifndef CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_RESTAURANTE_H
#define CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_RESTAURANTE_H

#include "Cliente.h"
#include "Plato.h"

class Restaurante {
    Cliente* clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    Plato* platos;
    int cantidadDePlatos;
    int capacidadDePlatos;
    void incrementarMemClientes();
    void incrementarMenPlatos();
    int buscarCliente(int) const;
    int buscarPlato(const char*) const;
    void actualizarAtributos(int,int,int);
    void imprimirEncabezado(ofstream&) const;
public:
    Restaurante();
    Restaurante& operator<(const char*);
    Restaurante& operator<=(const char*);
    Restaurante& operator<<=(const char*);
    const Restaurante& operator>>(const char*) const;
    ~Restaurante();
};

#endif //CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_RESTAURANTE_H
