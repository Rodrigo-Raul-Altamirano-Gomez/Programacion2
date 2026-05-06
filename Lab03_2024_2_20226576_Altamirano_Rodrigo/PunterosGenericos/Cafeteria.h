//
// Created by hrodic on 22/04/2026.
//

#ifndef PUNTEROSGENERICOS_CAFETERIA_H
#define PUNTEROSGENERICOS_CAFETERIA_H

#include "enums.h"
#include <fstream>
using namespace std;

void cargarInventario(const char*,void*&);
bool LeerLineaInventario(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
void cargarMenu(const char*,void*&);
bool LeerLineaMenu(void*&,ifstream&);
void actualizarMenu(const char*,void*,void*);
bool LeerLineaInsumosBebidas(char*,char*,double&,char&,ifstream&);
void* BuscarBebidaOInsumo(const char*,void*);
void AñadirInsumoALaBebida(double,char,void*,void*&);
void  reporteMenu(const char*,void*);
const char* ObtenerTipoBebida(char);

#endif //PUNTEROSGENERICOS_CAFETERIA_H
