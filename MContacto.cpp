#include "MContacto.h"


//Constructores
MContacto::MContacto(){}

MContacto::MContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto):Mensaje(codigo, numTelRemitente, fechayHora){
    this->contacto = contacto;
}

MContacto::~MContacto(){};
