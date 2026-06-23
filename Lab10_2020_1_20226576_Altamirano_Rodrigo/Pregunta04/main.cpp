#include "Bibliotecas/Reserva.h"

int main() {
    Reserva reserva;
    reserva.carga("ArchivosDeDatos/Aulas.csv","ArchivosDeDatos/Miembros.csv");
    reserva.asigna(4);
    reserva.imprime("ArchivosDeReporte/Reporte.txt");
    return 0;
}
