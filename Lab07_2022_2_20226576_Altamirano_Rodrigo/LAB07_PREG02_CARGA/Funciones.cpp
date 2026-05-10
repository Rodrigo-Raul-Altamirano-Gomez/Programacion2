//
// Created by hrodic on 9/05/2026.
//

#include "Funciones.h"

void cargarMedicos(Medico* arrMedicos) {
    ifstream archMedicos("medicos.csv",ios::in);
    int cantMedicos=0;
    while (archMedicos>>arrMedicos[cantMedicos]) cantMedicos++;
}

void cargarPacientes(Paciente* arrPacientes) {
    ifstream archPacientes("pacientes.csv",ios::in);
    int cantPacientes=0;
    while (archPacientes>>arrPacientes[cantPacientes]) cantPacientes++;
}

void procesarCitas(Paciente* arrPacientes,const Medico* arrMedicos) {
    ifstream archCitas("citas.csv",ios::in);
    Cita cita;
    while (archCitas>>cita) {
        cita<=arrMedicos;
        int posPaciente=cita.buscarPaciente(arrPacientes);
        if (posPaciente>=0) arrPacientes[posPaciente]+=cita;
    }
}

void actualizarGastos(Paciente* arrPacientes) {
    for (int i=0;arrPacientes[i].getNombre();i++) {
        arrPacientes[i]++;
    }
}

void EmitirReporte(const Paciente* arrPacientes) {
    ofstream archReporte("Reporte.txt",ios::out);
    for (int i=0;arrPacientes[i].getNombre();i++) {
        archReporte<<arrPacientes[i];
    }
}