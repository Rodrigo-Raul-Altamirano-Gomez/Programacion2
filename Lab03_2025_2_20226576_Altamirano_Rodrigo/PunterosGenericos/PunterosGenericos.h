//
// Created by hrodic on 24/04/2026.
//

#ifndef PUNTEROSGENERICOS_PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargarstreamers(void*&);
bool LeerLineaStreamers(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
void PruebaStreamers(void*);
void cargarcomentarios(void*&);
bool LeerLineaComentarios(void*&,ifstream&);
void PruebaComentarios(void*);
void actualizarcomentarios(void*,void*);
void AñadirComentarioStreamer(void*,void*&);
char* CopiarCadenaExacta(const char*);
void imprimestreamers(void*);
void EmitirComentariosStreamer(void*,ofstream&);

#endif //PUNTEROSGENERICOS_PUNTEROSGENERICOS_H
