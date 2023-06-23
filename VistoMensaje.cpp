#include "VistoMensaje.h"
#include <string>
#include <stdlib.h>

using namespace std;

//Constructores

VistoMensaje::VistoMensaje(){}

VistoMensaje::VistoMensaje(string codigoMsj, int numTelDestinatario, DtFechaHora* fecHoraVisto ,bool visto){
    this-> codigoMsj = codigoMsj;
    this-> numTelDestinatario = numTelDestinatario;
    this-> fecHoraVisto = fecHoraVisto;
    this->visto = visto;
}

//Gettes

string VistoMensaje::getCodigo(){
    return this->codigoMsj;
}

int VistoMensaje::getDestinatario(){
    return this->numTelDestinatario;
}


DtFechaHora* VistoMensaje::getfecHoraVisto(){
    return this->fecHoraVisto;
}

bool VistoMensaje::getVisto(){
    return this->visto;
}

//Setters

void VistoMensaje::setCodigo(string codigoMsj){
    this->codigoMsj = codigoMsj;
}

void VistoMensaje::setDestinatario(int numTelDestinatario){
    this->numTelDestinatario = numTelDestinatario;
}

void VistoMensaje::setFecHoraVisto(DtFechaHora* fecHoraVisto){
    this->fecHoraVisto = fecHoraVisto;
}

void VistoMensaje::setVisto(){
    this->visto = true;
}

//Destructor

VistoMensaje::~VistoMensaje(){}
