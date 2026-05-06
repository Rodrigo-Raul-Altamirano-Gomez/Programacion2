#include "PunterosGenericos.h"

int main() {
    void* streamers,*comentarios;

    cargarstreamers(streamers);
    cargarcomentarios(comentarios);
    actualizarcomentarios(streamers,comentarios);
    imprimestreamers(streamers);

    return 0;
}
