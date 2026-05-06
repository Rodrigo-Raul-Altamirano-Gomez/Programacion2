//
// Created by hrodic on 19/04/2026.
//

#ifndef LABORATORIO05_05_2021_2_PUNTEROSYPUNTEROGENERICOS_H
#define LABORATORIO05_05_2021_2_PUNTEROSYPUNTEROGENERICOS_H

#include <fstream>
#include <iostream>
using namespace std;

void cargaDeLibros(void*& libros);
bool LeerLineaLibros(void*& libro,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
void reporteDeLibros(const void*);
void cargaDeUsuarios(int*&,char*&,char**&);
bool LeerLineaUsuarios(int&,char&,char*&,ifstream&);
void IncrementarMemoriaCarnes(int*&,int,int);
void IncrementarMemoriaTipos(char*&,int,int);
void IncremenentarMemoriaNombres(char**&,int,int);
void reporteDeUsuarios(const int*,const char*,char**);
void reporteUsuariosInhabilitados(void*,int*,char*,char**);
bool LeerLineaPrestamo(void*&,ifstream&);
void DeletearDeuda(void**);
void EmitirReporte(void*,int*,char*,char**,void**,int);
void ImprimirDeudaUsuario(void**,void**,int,int,double&,ofstream&);
int BuscarLibro(const char*,void**);

#endif //LABORATORIO05_05_2021_2_PUNTEROSYPUNTEROGENERICOS_H
