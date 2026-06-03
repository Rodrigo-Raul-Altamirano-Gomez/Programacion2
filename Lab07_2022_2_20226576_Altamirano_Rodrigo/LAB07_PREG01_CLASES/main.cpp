#include "Paciente.h"

int main() {
    ifstream archMedicos("medicos.csv",ios::in);
    ifstream archPacientes("pacientes.csv",ios::in);
    ifstream archCitas("citas.csv",ios::in);
    ofstream archReporte("Reporte.txt",ios::out);
    Medico arrMedicos[5]{};
    Paciente paciente;
    Cita cita;
    archMedicos>>arrMedicos[0];
    archPacientes>>paciente;
    archCitas>>cita;
    arrMedicos[0].setCodigo(cita.getCodigo());
    cita<=arrMedicos;
    paciente+=cita;
    paciente++;
    archReporte<<paciente;
    return 0;
}
