#include "Bibliotecas/GestorStreamers.h"

int main() {
    GestorStreamers gestor_streamers;
    gestor_streamers.cargar_datos_streamers("ArchivosDeDatos/streamers.csv");
    gestor_streamers.actualizar_datos_metricas("ArchivosDeDatos/metricas.csv");
    gestor_streamers.generar_reporte();
    return 0;
}
