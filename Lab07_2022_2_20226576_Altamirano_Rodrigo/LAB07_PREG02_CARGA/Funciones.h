//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG02_CARGA_FUNCIONES_H
#define LAB07_PREG02_CARGA_FUNCIONES_H

#include "Paciente.h"

void cargarMedicos(Medico*);
void cargarPacientes(Paciente*);
void procesarCitas(Paciente*,const Medico*);
void actualizarGastos(Paciente*);
void EmitirReporte(const Paciente* arrPacientes);

#endif //LAB07_PREG02_CARGA_FUNCIONES_H
