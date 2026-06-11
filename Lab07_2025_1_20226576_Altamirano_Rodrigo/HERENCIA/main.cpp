#include "Bibliotecas/MinisterioDeTransportes.h"

int main() {
    MinisterioDeTransportes ministerio_de_transportes;
    ministerio_de_transportes.cargar_drones("ArchivosDeDatos/");
    ministerio_de_transportes.procesar_todos_los_eventos("ArchivosDeDatos/");
    ministerio_de_transportes.imprimir("ArchivosDeReporte/Reporte.txt");
    return 0;
}
