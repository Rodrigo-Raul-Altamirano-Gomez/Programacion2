//
// Created by hrodic on 14/06/2026.
//

#include "DetalleComanda.h"

#include <iomanip>

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

DetalleComanda::DetalleComanda() {
    this->pedido=nullptr;
}

DetalleComanda::DetalleComanda(const DetalleComanda &detalle_comanda) : DetalleComanda() {
    *this=detalle_comanda;
}

DetalleComanda &DetalleComanda::operator=(const DetalleComanda &detalle_comanda) {
    if (this!=&detalle_comanda) {
        this->id=detalle_comanda.id;
        this->setPedido(detalle_comanda.pedido);
    }
    return *this;
}

void DetalleComanda::setPedido(const Producto *pedido) {
    delete this->pedido;
    if (pedido) this->pedido=pedido->clonar();
    else this->pedido=nullptr;
}

bool DetalleComanda::leer(ifstream &archComandas) {
    int id;
    char car,tipoProducto;
    Producto* producto;
    if (archComandas>>id) {
        this->id=id;
        archComandas>>car>>tipoProducto>>car;
        if (tipoProducto=='B') producto=new Bebida;
        else if (tipoProducto=='E') producto=new Entrada;
        else producto=new PlatoFondo;
        producto->leer(archComandas);
        this->setPedido(producto);
        return true;
    }
    return false;
}

int DetalleComanda::getProteinaPedido() const {
    return this->pedido->getProteina();
}

void DetalleComanda::imprimir(ofstream &archReporte) const {
    archReporte<<setw(10)<<" "<<"Codigo de comanda: "<<this->id<<endl;
    this->pedido->imprimir(archReporte);
    archReporte<<endl;
}

DetalleComanda::~DetalleComanda() {
    delete this->pedido;
}
