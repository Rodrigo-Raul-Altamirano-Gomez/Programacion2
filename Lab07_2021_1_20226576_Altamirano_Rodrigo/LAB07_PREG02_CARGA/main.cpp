#include "Funciones.h"

int main() {
    Conductor* arrConductores;
    int cantConductores;
    cargarConductores(arrConductores,cantConductores);
    procesarFaltas(arrConductores,cantConductores);
    completarInfracciones(arrConductores,cantConductores);
    calcularTotales(arrConductores,cantConductores);
    emitirReporte(arrConductores,cantConductores,"SinAmnistia.txt");
    aplicarAmnistia(arrConductores,cantConductores);
    emitirReporte(arrConductores,cantConductores,"ConAmnistia.txt");
    return 0;
}
