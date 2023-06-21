#include "Mensaje.h"
#include <string>
#include <stdlib.h>

using namespace std;

//Constructores

Mensaje::Mensaje(){}

Mensaje::Mensaje(string codigo, int numTelRemitente,DtFechaHora* fechayHora){
    this-> codigo = codigo;
    this-> numTelRemitente = numTelRemitente;
    this-> fechayHora = fechayHora;
}

//Gettes

string Mensaje::getCodigo(){
    return this->codigo;
}

DtFechaHora* Mensaje::getFechayHora(){
    return this->fechayHora;
}

int Mensaje::getNumRemitente(){
    return this->numTelRemitente;
}

/* DtMensaje Mensaje::seleccionar(){
    return NULL;
} */

//Setters

void Mensaje::setCodigo (string codigo){
    this->codigo = codigo;
}

//Destructor

Mensaje::~Mensaje(){}

