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

DtMContacto* MContacto::mostrarDatosM()
{
    DtMContacto* DtmsjContacto = new DtMContacto(this->getCodigo(),this->getNumRemitente(),this->getFechayHora(), this->getContacto());
    DtMensaje *Dtmsj = DtmsjContacto;
    DtmsjContacto = dynamic_cast<DtMContacto*>(Dtmsj);

    return DtmsjContacto;
}

//Setters
void MContacto::setContacto(DtUsuario contacto){
    this->contacto = contacto;
}

MContacto::~MContacto(){};
