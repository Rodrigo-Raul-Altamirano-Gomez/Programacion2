//
// Created by hrodic on 19/04/2026.
//

#ifndef PREGUNTA2_BIB_FUNC_PREG2_H
#define PREGUNTA2_BIB_FUNC_PREG2_H

#include <fstream>
using namespace std;

void leerPrestamos(void* usuarios);
bool LeerLineaPrestamos(int&,void*&,ifstream&);
int BuscarUsuario(int,void*);
void AñadirLibroPrestadoUsuario(void* libroPrestadoUsuario,void* usuario);
void IncrementarMemoriaLibrosUsuario(void*& librosPrestados,void* numLibros,int& capacidad);
void imprimirPrestamos(void* usuarios);
void ImprimirLibrosPrestados(void**,int,ofstream&);
int contarDatos(void*);
void qsort(void*,int);
void OrdenarLibrosPrestados(void*,int);
void OrdenarUsuario(void*,int,int);

#endif //PREGUNTA2_BIB_FUNC_PREG2_H
