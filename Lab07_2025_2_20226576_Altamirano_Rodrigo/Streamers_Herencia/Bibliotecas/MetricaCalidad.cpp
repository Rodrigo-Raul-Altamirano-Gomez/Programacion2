//
// Created by hrodic on 1/06/2026.
//
#include <iomanip>
#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad(const MetricaCalidad &metricaCalidad) : MetricaCalidad() {
    *this=metricaCalidad;
}

MetricaCalidad &MetricaCalidad::operator=(const MetricaCalidad &metricaCalidad) {
    if (this!=&metricaCalidad) {
        Metrica::operator=(metricaCalidad);

        this->bitrate_promedio_kbps=metricaCalidad.bitrate_promedio_kbps;
        this->porcentaje_frames_perdidos=metricaCalidad.porcentaje_frames_perdidos;
        this->fps_promedio=metricaCalidad.fps_promedio;
    }
    return *this;
}

void MetricaCalidad::setBitratePromedio(int bitratePromedio) {
    this->bitrate_promedio_kbps=bitratePromedio;
}

void MetricaCalidad::setPorcentajePerdidaFrames(double porcentajeFramesPerdidos) {
    this->porcentaje_frames_perdidos=porcentajeFramesPerdidos;
}

void MetricaCalidad::setFpsPromedio(int fpsPromedio) {
    this->fps_promedio=fpsPromedio;
}

int MetricaCalidad::getBitratePromedio() const {
    return this->bitrate_promedio_kbps;
}

double MetricaCalidad::getPorcentajePerdidaFrames() const {
    return this->porcentaje_frames_perdidos;
}

int MetricaCalidad::getFpsPormedio() const {
    return this->fps_promedio;
}

void MetricaCalidad::leer(ifstream &archMetricas) {
    char car;
    Metrica::leer(archMetricas);
    archMetricas>>this->bitrate_promedio_kbps>>car>>this->porcentaje_frames_perdidos>>car>>this->fps_promedio;
    archMetricas.ignore();
}

void MetricaCalidad::imprimir(ofstream &archReporte) const {
    char* descripcion=this->getDescripcion();
    Metrica::imprimir(archReporte);
    archReporte<<setw(10)<<this->bitrate_promedio_kbps<<setw(7)<<this->porcentaje_frames_perdidos;
    archReporte<<setw(7)<<this->fps_promedio<<descripcion<<endl;
    delete[] descripcion;
}

ifstream& operator>>(ifstream& archMetricas,MetricaCalidad& metrica_calidad) {
    metrica_calidad.leer(archMetricas);
    return archMetricas;
}

ofstream& operator<<(ofstream& archReporte,const MetricaCalidad& metrica_calidad) {
    metrica_calidad.imprimir(archReporte);
    return archReporte;
}