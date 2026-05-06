#include "PunterosGenericos.h"
using namespace std;

int main() {
    void *clientes,*reserva;
    cargaclientes(clientes);
    creareserva(reserva);
    cargareservar(clientes,reserva);
    reportefinal(reserva);
    return 0;
}
