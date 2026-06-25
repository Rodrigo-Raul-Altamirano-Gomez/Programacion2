#include "Bibliotecas/AnalisisSentimiento.h"

int main() {
    AnalisisSentimiento analisis;

    analisis.cargar_lexicon();
    analisis.cargar_comentarios_restaurantes();
    analisis.ordenar_comentarios();
    analisis.imprimir_analisis();

    return 0;
}
