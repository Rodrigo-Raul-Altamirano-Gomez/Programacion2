//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxiliares.h"
#include "ProductoEntregado.h"

void ProductoEntregado::setCodigo(const char *codigoProducto) {
    this->codigo=CopiarCadenaExacta(codigoProducto);
}

void ProductoEntregado::setPrecio(double precio) {
    this->precio=precio;
}

const char *ProductoEntregado::getCodigo() {
    return this->codigo;
}
