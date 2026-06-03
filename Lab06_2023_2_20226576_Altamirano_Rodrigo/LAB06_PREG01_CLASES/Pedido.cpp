//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxiliares.h"
#include "Pedido.h"

bool operator>>(ifstream& archPedidos,Pedido& pedido) {
    pedido.codigo=LeerCadenaExacta(archPedidos);
    if (pedido.codigo) {
        archPedidos>>pedido.dni_cliente;
        return true;
    }
    return false;
}

const char *Pedido::getCodigo() const {
    return this->codigo;
}

double Pedido::getPrecio() const {
    return this->precio_producto;
}

void Pedido::setPrecio(double precio) {
    this->precio_producto=precio;
}

int Pedido::getDni() {
    return this->dni_cliente;
}
