//
// Created by hrodic on 14/06/2026.
//

#include "PlatoFondo.h"

#include <iomanip>

PlatoFondo::PlatoFondo(const PlatoFondo &plato_fondo) : PlatoFondo() {
    *this=plato_fondo;
}

PlatoFondo &PlatoFondo::operator=(const PlatoFondo &plato_fondo) {
    if (this!=&plato_fondo) {
        Producto::operator=(plato_fondo);
        this->proteina=plato_fondo.proteina;
    }
    return *this;
}

Producto *PlatoFondo::clonar() const {
    PlatoFondo* platoFondoClonado=new PlatoFondo(*this);
    return platoFondoClonado;
}

void PlatoFondo::leer(ifstream &archComandas) {
    Producto::leer(archComandas);
    archComandas>>this->proteina;
}

void PlatoFondo::imprimir(ofstream &archReporte) const {
    Producto::imprimir(archReporte);
    archReporte<<setw(10)<<" "<<"Proteina: "<<this->proteina<<endl;
}
