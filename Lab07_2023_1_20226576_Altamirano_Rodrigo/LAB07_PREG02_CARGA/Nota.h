//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB07_PREG01_CLASES_NOTA_H
#define LAB07_PREG01_CLASES_NOTA_H

class Nota {
    char* codCurso;
    int ciclo;
    int nota;
public:
    void setCodigoCurso(const char*);
    void setCiclo(int);
    void setNota(int);
    const char* getCodigoCurso() const ;
    int getCiclo() const ;
    int getNota() const ;
};


#endif //LAB07_PREG01_CLASES_NOTA_H
