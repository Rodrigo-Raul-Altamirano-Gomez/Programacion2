//
// Created by hrodic on 21/04/2026.
//

#ifndef PUNTEROSGENERICOS_PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargaclientes(void*&);
bool LeerLineaClientes(void*&,ifstream&);
char* LeeCadenaExacta(ifstream&,char);
void creareserva(void*&);
bool LeerLineaLibros(void*&,ifstream&);
void cargareservar(void*,void*);
bool LeerLineaPedidos(int&,char*,ifstream&);
char* BuscarCliente(int,void*);
void* BuscarLibro(const char*,void*);
void AñadirPedidoAlLibro(int,const char*,void*);
void reportefinal(void*);

#endif //PUNTEROSGENERICOS_PUNTEROSGENERICOS_H
