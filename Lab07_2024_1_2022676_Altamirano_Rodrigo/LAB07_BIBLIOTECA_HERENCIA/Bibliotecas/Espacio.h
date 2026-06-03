//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESPACIO_H
#define LAB07_BIBLIOTECA_HERENCIA_ESPACIO_H


class Espacio {
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
    char getContenido() const;
    void setContenido(char);
    void setPosX(int);
    void setPosY(int);
};


#endif //LAB07_BIBLIOTECA_HERENCIA_ESPACIO_H
