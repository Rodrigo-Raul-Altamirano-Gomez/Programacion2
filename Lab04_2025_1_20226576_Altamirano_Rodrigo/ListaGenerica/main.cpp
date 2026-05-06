#include "BibliotecaGenerica.h"
#include "BibliotecaRegistros.h"
#include "BibliotecaEnteros.h"

using namespace std;

int main() {
    void* lista;

    creaLista(lista,leenum,clasificaentero,"numeros2.txt");
    imprimeLista(lista,imprimenum,"Repnum.txt");

    creaLista(lista,leeregistro,clasificaregistro,"RegistroDeFaltas1.csv");
    imprimeLista(lista,imprimeregistro,"Repfalta.txt");

    return 0;
}
