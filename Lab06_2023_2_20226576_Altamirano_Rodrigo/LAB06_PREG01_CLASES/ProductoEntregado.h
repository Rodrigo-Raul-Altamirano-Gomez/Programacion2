//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB06_PREG01_CLASES_PRODUCTOENTREGADO_H
#define LAB06_PREG01_CLASES_PRODUCTOENTREGADO_H


class ProductoEntregado {
    char* codigo;
    double precio;
public:
    void setCodigo(const char*);
    void setPrecio(double);
    const char* getCodigo();
};


#endif //LAB06_PREG01_CLASES_PRODUCTOENTREGADO_H
