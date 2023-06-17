#include "DtEstado.h"
//Constructores
DtEstado::DtEstado(){}

DtEstado::DtEstado(string texto, DtFechaHora fechayHora){
    this-> texto=texto;
    this-> fechayHora=fechayHora;
}

//Gettes
string DtEstado::getTexto(){
    return this->texto=texto;
}
DtFechaHora DtEstado::getFechayHora(){
    return this->fechayHora=fechayHora;
}

//Destructor
DtEstado::~DtEstado(){};