//
// Created by hrodic on 21/04/2026.
//

#ifndef PUNTEROSGENERICOS_2023_2_PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_2023_2_PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargaproductos(void*&);
bool LeerLineaProductos(void*&,ifstream&);
char* LeerCadenaExacta(ifstream&,char);
void cargaclientes(void*&);
bool LeerLineaClientes(void*&,ifstream&);
void cargapedidos(void*,void*);
bool LeerLienaPedidos(int&,void*&,ifstream&);
void** BuscarCliente(int,void*);
void DeletearPedido(void**);
void** BuscarProducto(const char*,void*);
void AñadirPedidoAlCliente(void*,void*&);

#endif //PUNTEROSGENERICOS_2023_2_PUNTEROSGENERICOS_H
