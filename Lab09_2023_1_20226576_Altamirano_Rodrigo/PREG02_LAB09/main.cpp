#include "Bibliotecas/Tesoreria.h"

int main() {
    Tesoreria OTeso;

    OTeso.cargarescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();

    return 0;
}
