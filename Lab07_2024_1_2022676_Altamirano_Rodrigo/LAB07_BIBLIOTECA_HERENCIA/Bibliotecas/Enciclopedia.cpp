//
// Created by hrodic on 25/05/2026.
//

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    this->volumen=0;
}

Enciclopedia::Enciclopedia(const Enciclopedia &enciclopedia) {
    *this=enciclopedia;
}

void Enciclopedia::leerEnciclopedia(ifstream &archLibros) {
    char car;
    this->leerLibro(archLibros);
    archLibros>>this->volumen>>car>>this->peso;
    this->setPeso(this->peso);
}

int Enciclopedia::getAltura() const {
    return Libro::getAltura();
}

int Enciclopedia::getAnchura() const {
    return Libro::getAnchura();
}

double Enciclopedia::getPeso() const {
    return this->peso;
}

void Enciclopedia::setColocado(bool colocado) {
    Libro::setColocado(colocado);
}

Enciclopedia &Enciclopedia::operator=(const Enciclopedia &enciclopedia) {
    if (this!=&enciclopedia) {
        Libro::operator=(enciclopedia);
        this->volumen=enciclopedia.volumen;
        this->peso=enciclopedia.peso;
    }
    return *this;
}

void Enciclopedia::imprimirEnciclopedia(ofstream &archReporte) const {
    this->imprimirLibro(archReporte);
}

ifstream& operator>>(ifstream& archLibros,Enciclopedia& enciclopedia) {
    enciclopedia.leerEnciclopedia(archLibros);
    return archLibros;
}

ofstream& operator<<(ofstream& archReporte,const Enciclopedia& enciclopedia) {
    enciclopedia.imprimirEnciclopedia(archReporte);
    return archReporte;
}
