//
// Created by hrodic on 14/06/2026.
//

#include "Restaurante.h"
#include <fstream>
#include <iomanip>
using namespace std;

void Restaurante::carga() {
    ifstream archComandas("ArchivosDeDatos/comandas2.csv",ios::in);
    DetalleComanda detalle_comanda;
    while (detalle_comanda.leer(archComandas)) {
        this->Ccomanda.encola(detalle_comanda);
    }
}

void Restaurante::elimina(int proteina) {
    int longCola=this->Ccomanda.getLongitud();
    for (int i=0;i<longCola;i++) {
        DetalleComanda detalle_comanda=this->Ccomanda.desencola();
        if (detalle_comanda.getProteinaPedido()!=proteina) this->Ccomanda.encola(detalle_comanda);
    }
}

void Restaurante::atiende() {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    int longCola=this->Ccomanda.getLongitud();
    archReporte<<fixed<<setprecision(2)<<setw(10)<<" "<<"Detalle de Comandas:"<<endl;
    archReporte<<setw(10)<<" "<<setfill('=')<<setw(50)<<" "<<setfill(' ')<<endl;
    for (int i=0;i<longCola;i++) {
        DetalleComanda detalle_comanda=this->Ccomanda.desencola();
        detalle_comanda.imprimir(archReporte);
    }
}
