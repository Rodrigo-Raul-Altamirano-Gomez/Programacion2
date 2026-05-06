#include <iostream>
#include "Bibliotecas/Funciones.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    char*** categorias;
    cargarCategorias("ArchivosDeDatos/categorias.csv",categorias);

    char*** streamers;
    int** fechasPromedios;
    long long** tiempoRepSeguidores;
    cargarStreamers("ArchivosDeDatos/streamers.csv",streamers,fechasPromedios,tiempoRepSeguidores);

    char*** comentarios;
    char*** etiquetas;
    cargarComentarios("ArchivosDeDatos/comentarios.csv",comentarios,etiquetas);
    imprimirReporte("ArchivosDeReporte/reporte.txt",categorias,streamers,fechasPromedios,tiempoRepSeguidores
        ,comentarios,etiquetas);

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}