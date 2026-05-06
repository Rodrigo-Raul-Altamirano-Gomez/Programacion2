//
// Created by hrodic on 16/04/2026.
//

#ifndef PUNTEROSMULTIPLES_LAB02_2025_2_FUNCIONES_H
#define PUNTEROSMULTIPLES_LAB02_2025_2_FUNCIONES_H

#include <fstream>
using namespace std;

void cargarCategorias(const char*,char***&);
bool LeeLineaCategoria(char**&,ifstream&);
char* LeeCadenaExacta(ifstream&,char);
void IncrementarMemoriaChar(char***&,int,int);
void cargarStreamers(const char*,char***&,int**&,long long**&);
bool LeerLineaStreamer(char**&,int*&,long long*&,ifstream&);
void IncrementarMemoriaInt(int**&,int,int);
void IncrementarMemoriaLongLong(long long**&,int,int);
void cargarComentarios(const char*,char***&,char***&);
bool LeeLineaComentario(char**&,char**&,ifstream&);
char** AsignacionExactaEtiqueta(ifstream&);
void CargarBuffer(char*,char**,int&);
void ConcatenarTexto(char*&,char*&);
void imprimirReporte(const char*,char***,char***,int**,long long**,char***,char***);
void ImprimirStreamers(const char*,char***,int**,long long**,char***,char***,ofstream&);
void ImprimirFecha(int,ofstream&);
void ImprimirEtiquetas(const char*,char***,char***,ofstream&);

#endif //PUNTEROSMULTIPLES_LAB02_2025_2_FUNCIONES_H
