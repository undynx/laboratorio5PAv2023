#include "VistoMensaje.h"
#include <string>
#include <stdlib.h>

using namespace std;

//Constructores

VistoMensaje::VistoMensaje(){
    this-> numTelDestinatario = 0;
    this-> fecHoraVisto = NULL;
    this->visto = false;
}

VistoMensaje::VistoMensaje(int numTelDestinatario, DtFechaHora* fecHoraVisto ,bool visto){
    this-> numTelDestinatario = numTelDestinatario;
    this-> fecHoraVisto = fecHoraVisto;
    this->visto = visto;
}

//Gettes

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
