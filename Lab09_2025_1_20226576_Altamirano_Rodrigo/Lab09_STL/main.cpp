#include "Bibliotecas/MinisterioDeTransporte.h"

int main() {
    MinisterioDeTransporte ministerio_de_transporte;

    ministerio_de_transporte.cargaDeInfracciones("ArchivosDeDatos/TablaDeInfracciones.csv");
    ministerio_de_transporte.cargaEmpresas("ArchivosDeDatos/EmpresasRegistradas.csv");
    ministerio_de_transporte.cargaVehiculos("ArchivosDeDatos/VehiculosRegistrados.csv");
    ministerio_de_transporte.cargaInfraccionesCometidas("ArchivosDeDatos/InfraccionesCometidas.csv");
    ministerio_de_transporte.reporteDeEmpresasConInfracciones("ArchivosDeReporte/Reporte.txt");
    ministerio_de_transporte.eliminaInfraccionesPagadas();
    ministerio_de_transporte.reporteDeEmpresasConInfracciones("ArchivosDeReporte/ReporteDepurado.txt");

    return 0;
}
