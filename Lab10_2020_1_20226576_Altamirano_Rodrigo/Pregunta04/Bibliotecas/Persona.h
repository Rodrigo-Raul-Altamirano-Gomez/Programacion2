//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA01_PERSONA_H
#define PREGUNTA01_PERSONA_H
#include <string>
#include <fstream>

class Persona {
    std::string nombre;
    int codigo;
    std::string distrito;
protected:
    virtual void leer(std::ifstream&);
    virtual void imprimir(std::ofstream&) const;
    friend std::ifstream& operator>>(std::ifstream&,Persona*);
    friend std::ofstream& operator<<(std::ofstream&,const Persona*);
public:
    Persona();
    Persona(const Persona&) = default;
    Persona& operator=(const Persona&) = default;
    std::string getNombre() const;
    int getCodigo() const;
    std::string getDistrito() const;
    virtual ~Persona() = default;
};


#endif //PREGUNTA01_PERSONA_H
