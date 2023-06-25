#include "MContacto.h"

//Constructores
MContacto::MContacto(){}

MContacto::MContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto):Mensaje(codigo, numTelRemitente, fechayHora){
    this->contacto = contacto;
}

//Getters
DtUsuario MContacto::getContacto(){
    return this->contacto;
}

//Setters
void MContacto::setContacto(DtUsuario contacto){
    this->contacto = contacto;
}

MContacto::~MContacto(){};
