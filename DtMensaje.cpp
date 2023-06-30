#include "DtMensaje.h"
//Constructores
DtMensaje::DtMensaje(){}

DtMensaje::DtMensaje(string codigo, int numRemitente, DtFechaHora* fechayHora){
    this->codigo = codigo;
    this->fechayHora = fechayHora;
    this->numRemitente = numRemitente;
}

//Getters
string DtMensaje::getCodigo(){
    return this->codigo;
}

DtFechaHora* DtMensaje::getFechayHora(){
    return this->fechayHora;
}

int DtMensaje::getNumRemitente(){
    return this->numRemitente;
}

//Destructor
DtMensaje::~DtMensaje(){};
