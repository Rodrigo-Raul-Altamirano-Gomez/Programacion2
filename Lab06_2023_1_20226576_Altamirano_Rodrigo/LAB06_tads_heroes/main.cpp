#include "arreglos_genericos.h"
#include "listas_genericas.h"
#include <cstdlib>

using namespace std;

int main() {
    void *arreglo_heroes,*lista_heroes;
    int cantidad_total_heroes;
    llenar_arreglo_heroes(arreglo_heroes,cantidad_total_heroes,"heroes_changelog_1223.csv");
    qsort(arreglo_heroes,cantidad_total_heroes,sizeof(void*),cmp_multicriterio_void);
    crear_lista_heroes(arreglo_heroes,lista_heroes,leer_heroe);
    imprimir_lista_heroes(lista_heroes,imprimir_registro_heroe);
    eliminar_lista_heroes_repetidos(lista_heroes,eliminar_registro);
    imprimir_lista_heroes(lista_heroes,imprimir_registro_heroe);
    return 0;
}
