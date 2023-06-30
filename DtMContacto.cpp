#include "DtMContacto.h"

//Constructores
DtMContacto::DtMContacto(){}

DtMContacto::DtMContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto):DtMensaje(codigo, numTelRemitente, fechayHora){
    this->contacto = contacto;
}

//Getters
DtUsuario DtMContacto::getContacto(){
    return this->contacto;
}

void DtMContacto::getDtM(){}

DtMContacto::~DtMContacto(){};
