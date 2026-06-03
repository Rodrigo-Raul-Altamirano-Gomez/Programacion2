//
// Created by hrodic on 1/06/2026.
//
#include <iomanip>
#include "MetricaBasica.h"

MetricaBasica::MetricaBasica(const MetricaBasica &metricaBasica) : MetricaBasica() {
    *this=metricaBasica;
}

MetricaBasica &MetricaBasica::operator=(const MetricaBasica &metricaBasica) {
    if (this!=&metricaBasica) {
        Metrica::operator=(metricaBasica);
        this->horas_transmitidas=metricaBasica.horas_transmitidas;
        this->espectadores_promedio=metricaBasica.espectadores_promedio;
    }
    return *this;
}

void MetricaBasica::setHorasTrans(double horasTrans) {
    this->horas_transmitidas=horasTrans;
}

void MetricaBasica::setEspecProm(int especProm) {
    this->espectadores_promedio=especProm;
}

double MetricaBasica::getHorasTrans() const {
    return this->horas_transmitidas;

}

int MetricaBasica::getEspecProm() const {
    return this->espectadores_promedio;
}

void MetricaBasica::leer(ifstream &archMetricas) {
    char car;
    Metrica::leer(archMetricas);
    archMetricas>>this->horas_transmitidas>>car>>this->espectadores_promedio;
    archMetricas.ignore();
}

void MetricaBasica::imprimir(ofstream &archReporte) const {
    char* descripcion=this->getDescripcion();
    Metrica::imprimir(archReporte);
    archReporte<<right<<setw(4)<<this->horas_transmitidas<<setw(7)<<this->espectadores_promedio<<"M";
    archReporte<<setw(5)<<" "<<descripcion<<endl;
    delete[] descripcion;
}

ifstream& operator>>(ifstream& archMetricas,MetricaBasica& metrica_basica) {
    metrica_basica.leer(archMetricas);
    return archMetricas;
}

ofstream& operator<<(ofstream& archReporte,const MetricaBasica& metrica_basica) {
    metrica_basica.imprimir(archReporte);
    return archReporte;
}
