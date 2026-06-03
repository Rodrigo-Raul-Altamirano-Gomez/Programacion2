#include "Conductor.h"

int main() {
    ifstream archConductores("Conductores.csv",ios::in);
    ifstream archInfracciones("Infracciones.csv",ios::in);
    ifstream arrchFaltas("RegistroDeFaltas.csv",ios::in);
    ofstream archReportePrueba("ReportePrueba.txt",ios::out);
    Conductor conductor;
    Infraccion infraccion;
    Falta falta;
    int fecha=20200716;
    archConductores>>conductor;
    arrchFaltas>>falta;
    archInfracciones>>infraccion;
    conductor+falta;
    infraccion.setCodigo(falta.getCodigo());
    conductor+infraccion;
    conductor*fecha;
    conductor++;
    archReportePrueba<<conductor;
    return 0;
}
