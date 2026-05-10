#include "Funciones.h"

int main() {
    Medico arrMedicos[50]{};
    Paciente arrPacientes[75]{};
    cargarMedicos(arrMedicos);
    cargarPacientes(arrPacientes);
    procesarCitas(arrPacientes,arrMedicos);
    actualizarGastos(arrPacientes);
    EmitirReporte(arrPacientes);
    return 0;
}
