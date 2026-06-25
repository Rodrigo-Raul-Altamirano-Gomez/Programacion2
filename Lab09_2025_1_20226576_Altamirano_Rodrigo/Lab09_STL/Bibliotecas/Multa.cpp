#include <iomanip>
//
// Created by hrodic on 25/06/2026.
//
using namespace std;
#include "Multa.h"

void Multa::setMulta(double multa) {
    this->multa=multa;
}

int Multa::getFecha() const {
    return this->fecha;
}

std::string Multa::getPlaca() const {
    return this->placa;
}

std::string Multa::getCodMulta() const {
    return this->codMulta;
}

double Multa::getMulta() const {
    return this->multa;
}

bool Multa::getPagada() const {
    return this->pagada;
}

int Multa::getFechaDePago() const {
    return this->fechaDePago;
}

bool Multa::leer(std::ifstream &input) {
    int diaMulta,mesMulta,anioMulta,diaPago=0,mesPago=0,anioPago=0;
    char car,pago;
    input>>diaMulta;
    if (input) {
        input>>car>>mesMulta>>car>>anioMulta>>car;
        this->fecha=diaMulta+mesMulta*100+anioMulta*10000;
        getline(input,this->placa,',');
        getline(input,this->codMulta,',');
        input>>pago;
        if (pago=='P') {
            this->pagada=true;
            input>>car>>diaPago>>car>>mesPago>>car>>anioPago;
        } else this->pagada=false;
        this->fechaDePago=diaPago+mesPago*100+anioPago*10000;
        return true;
    } else return false;
}

void Multa::imprimir(std::ofstream &output) const {
    output<<left<<setw(15)<<this->placa;
    Multa::imprimirFecha(output,this->fecha);
    output<<setw(24)<<this->codMulta<<setw(18)<<this->multa<<setw(7)<<" "<<left;
    if (this->pagada) {
        output<<setw(10)<<"SI";
        Multa::imprimirFecha(output,this->getFechaDePago());
    } else output<<setw(7)<<"NO";
    output<<endl;
}

void Multa::imprimirFecha(std::ofstream &output,int fecha) {
    int dia,mes,anio,res;
    char car='/';
    anio=fecha/10000, res=fecha%10000, mes=res/100, dia=res%100;
    output<<right<<setfill('0')<<setw(2)<<dia<<car<<setw(2)<<mes<<car<<anio<<setfill(' ');
}

std::ifstream& operator>> (std::ifstream& input, Multa& multa) {
    multa.leer(input);
    return input;
}

std::ofstream& operator<< (std::ofstream& output, const Multa& multa) {
    multa.imprimir(output);
    return output;
}