#include "Cafeteria.h"

int main() {
    void *inventario,*menu;

    cargarInventario("inventario.csv",inventario);

    cargarMenu("menu.csv",menu);
    actualizarMenu("insumos-bebidas.csv",inventario,menu);
    reporteMenu("menu.txt",menu);

    return 0;
}
