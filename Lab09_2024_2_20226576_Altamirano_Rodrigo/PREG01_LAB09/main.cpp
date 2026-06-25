#include "Bibliotecas/AnalisisSentimiento.h"

using namespace std;

int main() {
    AnalisisSentimiento analisis;

    analisis.cargar_lexicon();
    analisis.cargar_comentarios_restaurantes();
    analisis.imprimir_analisis();

    return 0;
}
