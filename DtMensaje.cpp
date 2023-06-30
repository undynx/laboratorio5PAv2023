#include "DtMensaje.h"
//Constructores
DtMensaje::DtMensaje(){}

DtMensaje::DtMensaje(string codigo, int numRemitente,DtFechaHora* fechayHora){
    this->codigo;
    this->fechayHora;
    this->numRemitente;
}

//Gettes
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
