//
// Created by hrodic on 3/05/2026.
//

#ifndef LAB06_TADS_HEROES_LISTAS_GENERICAS_H
#define LAB06_TADS_HEROES_LISTAS_GENERICAS_H

#include <fstream>
using namespace std;

void crear_lista_heroes(void*,void*&,void* (*)(void*));
void* leer_heroe(void*);
char* CopiarCadenaExacta(const char*);
void eliminar_registro(void*);
void imprimir_lista_heroes(void*,void (*)(void*,ofstream&));
void imprimir_registro_heroe(void*,ofstream&);
void eliminar_lista_heroes_repetidos(void*&,void (*)(void*));
void EliminarNodo(void*,void*,void (*)(void*));

#endif //LAB06_TADS_HEROES_LISTAS_GENERICAS_H
