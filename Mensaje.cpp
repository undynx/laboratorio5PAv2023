#include "Mensaje.h"
#include <string>

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

DtMensaje Mensaje::seleccionar(){
    
}

//Setters

void Mensaje::setCodigo (string codigo){
    this->codigo = codigo;
}

//Destructor

Mensaje::~Mensaje(){}

