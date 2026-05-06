#include "BibliotecaColaGenerica.h"
#include "FuncionesLaboratorio01.h"

int main() {
    void* cola;
    creaCola(cola,leenumero,"numeros_aleatorios.txt");
    imprimir(cola,imprimenumero,"prueba_numeros.txt");
    atiendeNumero(cola);

    return 0;
}
