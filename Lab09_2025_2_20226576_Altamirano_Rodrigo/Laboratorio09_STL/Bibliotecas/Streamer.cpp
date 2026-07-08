#include <iomanip>
//
// Created by hrodic on 26/06/2026.
//
using namespace std;
#include "Streamer.h"

std::string Streamer::getCanal() const {
    return this->canal;
}

int Streamer::getFecha() const {
    return this->fecha;
}

Categoria Streamer::getCategoria() const {
    return this->categoria;
}

std::string Streamer::getEtiquetasStr() const {
    return this->etiquetasStr;
}

std::string Streamer::getIdioma() const {
    return this->idioma;
}

void Streamer::leer(std::ifstream& input) {
    string canal,codCategoria;
    getline(input,canal,',');
    if (input) {
        int dia,mes,anio;
        char car;
        this->canal=canal;
        input>>dia>>car>>mes>>car>>anio>>car;
        this->fecha=dia+mes*100+anio*10000;
        getline(input,codCategoria,',');
        this->categoria.setCodigo(codCategoria);
        getline(input,this->etiquetasStr,',');
        getline(input,this->idioma);
    }
}

void Streamer::imprimir(std::ofstream& output) const {
    output<<left<<setw(10)<<"CANAL:"<<  this->canal<<endl;
    output<<setw(10)<<"FECHA:";
    this->imprimirFecha(output);
    output<<endl<<left<<setw(10)<<"LENGUEAJE:"<<this->idioma<<endl;
    output<<"CATEGORIA:"<<endl;
    output<<this->categoria;
    output<<"ETIQUETAS STR: "<<this->etiquetasStr<<endl;
    output<<"ETIQUETAS:"<<endl;
    for (int cont=0;cont<this->etiquetasVector.size();cont++) {
        output<<right<<setw(4)<<cont+1<<") ";
        output<<this->etiquetasVector[cont];
    }
    output<<"COMENTARIOS:"<<endl;
    for (int cont=0;cont<this->comentarios.size();cont++) {
        output<<right<<setw(4)<<cont+1<<") "<<this->comentarios[cont]<<endl;
    }
}

void Streamer::imprimirFecha(std::ofstream &output) const {
    int dia,mes,anio,res;
    char car='/';
    anio=this->fecha/10000, res=this->fecha%10000, mes=res/100, dia=res%100;
    output<<right<<setfill('0')<<setw(2)<<dia<<car<<setw(2)<<mes<<car<<anio<<setfill(' ');
}

bool Streamer::operator<(const Streamer &streamer) const {
    return this->categoria<streamer.categoria or (this->categoria==streamer.categoria and this->fecha<streamer.fecha);
}

void Streamer::setCategoria(const Categoria &categoria) {
    this->categoria=categoria;
}

void Streamer::completarComentarios(const std::list<Comentario> &comentarios) {
    for (auto comentario=comentarios.begin();comentario!=comentarios.end();comentario++) {
        if ((*comentario).getCanal()==this->canal) this->comentarios.push_back((*comentario).getComentario());
    }
}

void Streamer::completarEtiquetas(const std::map<std::string, Etiqueta> &etiquetas) {
    size_t posEncontrada,posAnterior=0;
    while (true) {
        posEncontrada=this->etiquetasStr.find("-",posAnterior);
        string codEtiqueta=this->etiquetasStr.substr(posAnterior,posEncontrada-posAnterior);
        auto etiqueta=etiquetas.find(codEtiqueta);
        if (etiqueta!=etiquetas.end()) this->etiquetasVector.push_back((*etiqueta).second);
        if (posEncontrada==string::npos) break;
        posAnterior=posEncontrada+1;
    }
}

std::ifstream& operator>>(std::ifstream& input,Streamer& streamer) {
    streamer.leer(input);
    return input;
}

std::ofstream& operator<<(std::ofstream& output,const Streamer& streamer) {
    streamer.imprimir(output);
    return output;
}
