//
// Created by hrodic on 3/06/2026.
//
#include <iomanip>
#include "CentralDeMonitoreo.h"

CentralDeMonitoreo::CentralDeMonitoreo() {
    this->cantidad_multas_registradas=0;
    this->total_multas_acumuladas=0;
}

void CentralDeMonitoreo::leer(ifstream &arch, const char *tipo) {
    arch.clear();
    arch.seekg(0,ios::beg);
    this->flota.cargar_drone(arch,tipo);
}

void CentralDeMonitoreo::cargar_infracciones(ifstream &arch) {
    int cantidad_multas;
    double total_monto_multas;
    arch.clear();
    arch.seekg(0,ios::beg);
    this->flota.actualizarDronesInfracciones(arch);
    this->flota.obtener_info_multas(cantidad_multas,total_monto_multas);
    this->cantidad_multas_registradas=cantidad_multas;
    this->total_multas_acumuladas=total_monto_multas;
}

void CentralDeMonitoreo::imprimir(ofstream &arch) const {
    arch<<setw(5)<<this->cantidad_multas_registradas<<setw(12)<<this->total_multas_acumuladas<<endl;
    arch<<this->flota<<endl;
}

ofstream& operator<<(ofstream& arch,const CentralDeMonitoreo& central_de_monitoreo) {
    central_de_monitoreo.imprimir(arch);
    return arch;
}
