//
// Created by hrodic on 8/06/2026.
//
#include <iomanip>
#include "Procesa.h"

Procesa::Procesa() {
    this->cantidad=0;
}

void Procesa::leer() {
    ifstream archFaltas("ArchivosDeDatos/RegistroDeFaltas.csv",ios::in);
    int licencia,codigoInfraccion,diaFalta,mesFalta,anioFalta;
    char car,placa[20];
    while (archFaltas>>licencia) {
        archFaltas>>car>>codigoInfraccion>>car>>diaFalta>>car>>mesFalta>>car>>anioFalta>>car>>placa;
        this->lregistro[this->cantidad].leeConductor(licencia);
        this->lregistro[this->cantidad].leeInfraccion(codigoInfraccion);
        this->lregistro[this->cantidad].setFecha(diaFalta+mesFalta*100+anioFalta*10000);
        this->lregistro[this->cantidad].setPlaca(placa);
        this->cantidad++;
    }
}

void Procesa::imprimir() const {
    ofstream archReportePrueba("ArchivosDeReporte/ReportePrueba.txt",ios::out);
    archReportePrueba<<fixed<<setprecision(2);
    archReportePrueba<<
    for (int i=0;i<this->cantidad;i++) {
        this->lregistro[i].
    }
}
