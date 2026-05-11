//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB02_PREG02_ALUMNO_CURSO_H
#define LAB02_PREG02_ALUMNO_CURSO_H

class Curso {
    char* ccurso;
    int ciclo;
    int nota;
    double credito;
public:
    Curso();
    Curso(const Curso&);
    void asignar(const Curso&);
    Curso& operator=(const Curso&);
    bool compare(const Curso&) const;
    bool operator==(const Curso&) const;
    int getCiclo() const;
    int getNota() const;
    double getCredito() const;
    void setCodigo(const char*);
    void setCiclo(int);
    void setNota(int);
    void setCreditos(double);
    ~Curso();
};


#endif //LAB02_PREG02_ALUMNO_CURSO_H
