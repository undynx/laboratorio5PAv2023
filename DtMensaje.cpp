#include "DtMensaje.h"
//Constructores
DtMensaje::DtMensaje(){}

DtMensaje::DtMensaje(string id, DtFechaHora fechayHora, bool visto){
    this->id=id;
    this->fechayHora=fechayHora;
    this->visto=visto;
}

//Gettes
string DtMensaje::getId(){
    this-> id=id;
}
DtFechaHora DtMensaje::getFechayHora(){
    this->fechayHora=fechayHora;
}
bool DtMensaje::getVisto(){
}

//Destructor
DtMensaje::~DtMensaje(){};