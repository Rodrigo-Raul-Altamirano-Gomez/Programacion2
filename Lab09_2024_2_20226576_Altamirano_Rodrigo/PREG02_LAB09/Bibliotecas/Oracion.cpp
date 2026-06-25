//
// Created by hrodic on 23/06/2026.
//
using namespace std;
#include <fstream>
#include "Oracion.h"

Oracion::Oracion() {
    this->polaridad_total=0;
    this->cantidad_palabras=0;
}

int Oracion::getPolaridadTotal() const {
    return this->polaridad_total;
}

void Oracion::tokenizar(const std::string &comentario_procesado,const std::map<std::string,int>& lexicon) {
    size_t posAnterior=0,posEncontrada;
    int polaridad;
    while (true) {
        string texto;
        posEncontrada=comentario_procesado.find(' ',posAnterior);
        texto=comentario_procesado.substr(posAnterior,posEncontrada-posAnterior);
        auto it=lexicon.find(texto);
        if (it!=lexicon.end()) polaridad=(*it).second;
        else polaridad=0;
        Palabra palabra(texto,polaridad);
        this->palabras.push_back(palabra);
        this->polaridad_total+=polaridad;
        this->cantidad_palabras++;
        if (posEncontrada==string::npos) break;
        posAnterior=posEncontrada+1;
    }
}

bool Oracion::operator<(const Oracion &oracion) const {
    return not (this->polaridad_total<=oracion.polaridad_total);
}

void Oracion::imprimir(std::ofstream &archReporte) const {
    for (auto iterador=this->palabras.begin();iterador!=this->palabras.end();iterador++) {
        archReporte<<(*iterador).getTexto()<<" ";
    }
    archReporte<<endl;
}
