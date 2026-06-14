//
// Created by hrodic on 12/06/2026.
//

#include "LVehiculos.h"

LVehiculos::LVehiculos() {
    this->lini=nullptr;
    this->lfin=nullptr;
}

void LVehiculos::agregarVehiculo(Vehiculo *vehiculo) {
    NodoLista* nuevoNodo=new NodoLista;
    nuevoNodo->unidad=vehiculo;
    if (not this->lini) this->lini=nuevoNodo;
    else this->lfin->sig=nuevoNodo;
    this->lfin=nuevoNodo;
}

void LVehiculos::buscarAgregarPedido(int cliente, const char *codProducto, int cantidad, double peso) {
    for (NodoLista* nodoActual=this->lini;nodoActual;nodoActual=nodoActual->sig) {
        if (nodoActual->unidad->getCliente()==cliente and
            nodoActual->unidad->getActCarga()+peso<=nodoActual->unidad->getMaxCarga()) {
            nodoActual->unidad->push(codProducto,cantidad,peso);
            break;
        }
    }
}

void LVehiculos::imprimir(ofstream &archReporte) const {
    for (NodoLista* nodoActual=this->lini;nodoActual;nodoActual=nodoActual->sig) {
        nodoActual->unidad->imprimir(archReporte);
    }
}

LVehiculos::~LVehiculos() {
    delete this->lini;
}
