//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB06_PREG01_CLASES_ESPACIO_H
#define LAB06_PREG01_CLASES_ESPACIO_H


class Espacio {
    char contenido;
    int posx;
    int posy;
public:
    void setPosiciones(int,int);
    void setOcupado(bool);
    bool getContenido();
};


#endif //LAB06_PREG01_CLASES_ESPACIO_H
