#include "DtMensaje.h"
//Constructores
DtMensaje::DtMensaje(){}

DtMensaje::DtMensaje(string codigo, int numRemitente,DtFechaHora* fechayHora){
    this->codigo=codigo;
    this->fechayHora=fechayHora;
    this->numRemitente=numRemitente;
}

//Gettes
string DtMensaje::getCodigo(){
    this-> codigo=codigo;
}
DtFechaHora* DtMensaje::getFechayHora(){
    this->fechayHora=fechayHora;
}
int DtMensaje::getNumRemitente(){
    this->numRemitente;
}

//Destructor
DtMensaje::~DtMensaje(){};