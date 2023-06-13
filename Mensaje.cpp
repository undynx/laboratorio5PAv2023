#include "Mensaje.h"
#include <string>
#include <stdlib.h>

using namespace std;

//Constructores

Mensaje::Mensaje(){}

Mensaje::Mensaje(string codigo, DtFechaHora fechayHora){
    this-> codigo = codigo;
    this-> fechayHora = fechayHora;
}

//Gettes

string Mensaje::getCodigo(){
    return this->codigo;
}

DtFechaHora Mensaje::getFechayHora(){
    return this->fechayHora;
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

