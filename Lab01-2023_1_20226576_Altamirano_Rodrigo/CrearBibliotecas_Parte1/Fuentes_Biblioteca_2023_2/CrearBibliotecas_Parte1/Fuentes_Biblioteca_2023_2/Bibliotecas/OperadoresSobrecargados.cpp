//
// Created by hrodic on 1/04/2026.
//
#include <cstring>
#include <iomanip>
#include "OperadoresSobrecargados.h"

ifstream& operator>>(ifstream& archLectura, Cliente& cliente) {
    if (archLectura>>cliente.dni) {
        archLectura.ignore();
        archLectura.getline(cliente.nombre, 50, ',');
        archLectura>>cliente.telefono;

        cliente.cantidadProductosEntregados=0;
        cliente.montoTotal=0;
    }

    return archLectura;
}

ifstream& operator>>(ifstream& archLectura, Producto& producto) {
    if (archLectura.getline(producto.codigo, 8, ',')) {
        archLectura.getline(producto.descripcion, 60, ',');
        archLectura>>producto.precio;
        archLectura.ignore();
        archLectura>>producto.stock;
        archLectura.ignore();

        producto.cantidadClientesServidos=0;
        producto.cantidadClientesNoServidos=0;
    }

    return archLectura;
}

ifstream& operator>>(ifstream& archLectura, Pedido& pedido) {
    if (archLectura.getline(pedido.codigoProducto, 8, ',')) {
        archLectura>>pedido.dniCliente;
        archLectura.ignore();

        pedido.precioProducto=0;
    }

    return archLectura;
}

void operator+=(Cliente* arregloClientes, const Pedido& pedido) {
    int posCliente=BuscarCliente(arregloClientes, pedido.dniCliente);

    if (posCliente>=0) {
        Cliente& cliente=arregloClientes[posCliente];

        strcpy(cliente.productosEntregados[cliente.cantidadProductosEntregados].codigo, pedido.codigoProducto);
        cliente.productosEntregados[cliente.cantidadProductosEntregados].precio=pedido.precioProducto;
        cliente.cantidadProductosEntregados++;
        cliente.montoTotal+=pedido.precioProducto;
    }
}

int BuscarCliente(Cliente* arregloClientes, int dniCliente) {
    for (int i=0; arregloClientes[i].dni > 0; i++) {
        if (arregloClientes[i].dni==dniCliente) return i;
    }
    return -1;
}

bool operator+=(Producto* arregloProductos, Pedido& pedido) {
    int posProducto=BuscarProducto(arregloProductos, pedido.codigoProducto);

    if (posProducto>=0) {
        Producto& producto=arregloProductos[posProducto];

        pedido.precioProducto=producto.precio;
        if (producto.stock>0) {
            producto.clientesServidos[producto.cantidadClientesServidos]=pedido.dniCliente;
            producto.cantidadClientesServidos++;
            producto.stock--;

            return true;
        }
        else {
            producto.clientesNoServidos[producto.cantidadClientesNoServidos]=pedido.dniCliente;
            producto.cantidadClientesNoServidos++;

            return false;
        }
    }

    return false;
}

int BuscarProducto(Producto* arregloProductos, const char* codigoProducto) {
    for (int i=0; strcmp(arregloProductos[i].codigo, "XXXXXXX") != 0; i++) {
        if (strcmp(arregloProductos[i].codigo, codigoProducto)==0) return i;
    }
    return -1;
}

ofstream& operator<<(ofstream& archEscritura, const Cliente& cliente) {
    archEscritura<<fixed<<setprecision(2);
    archEscritura<<right<<cliente.dni<<setw(3)<<" "<<left<<setw(45)<<cliente.nombre;
    archEscritura<<right<<setfill('0')<<setw(9)<<cliente.telefono<<setfill(' ');
    archEscritura<<setw(12)<<cliente.montoTotal<<setw(3)<<" "<<"Productos Entregados: "<<left;
    if (cliente.cantidadProductosEntregados>0) {
        for (int i=0; i<cliente.cantidadProductosEntregados; i++) {
            archEscritura<<setw(10)<<cliente.productosEntregados[i].codigo;
        }
        archEscritura<<endl;
    }
    else archEscritura<<"NO SE LE ENTREGARON PRODUCTOS."<<endl;

    return archEscritura;
}

ofstream& operator<<(ofstream& archEscritura, const Producto& producto) {
    archEscritura<<fixed<<setprecision(2);
    archEscritura<<left<<setw(10)<<producto.codigo<<setw(55)<<producto.descripcion;
    archEscritura<<right<<setw(7)<<producto.precio<<setw(5)<<producto.stock<<endl;
    archEscritura<<left<<setw(23)<<"Clientes atendidos:"<<right;
    ImprimirClientes(archEscritura, producto.clientesServidos, producto.cantidadClientesServidos, true);
    archEscritura<<"Clientes no atendidos: ";
    ImprimirClientes(archEscritura,producto.clientesNoServidos, producto.cantidadClientesNoServidos, false);

    return archEscritura;
}

void ImprimirClientes(ofstream& archEscritura, const int* clientes, int cantidadClientes, bool servidos) {
    if (cantidadClientes>0) {
        for (int i=0; i<cantidadClientes; i++) {
            archEscritura<<clientes[i]<<setw(4)<<" ";
        }
        archEscritura<<endl;
    }
    else {
        servidos ? archEscritura<<"NO SE ATENDIERON PEDIDOS."<<endl:archEscritura<<"NO HAY CLIENTES SIN ATENDER."<<endl;
    }
}