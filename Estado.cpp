#include "Estado.h"

//Constructores
Estado::Estado(){}

Estado::Estado(string texto, DtFechaHora fechayHora) {
    this->texto = texto;
    this->fechayHora = fechayHora;
}

//Getters
string Estado::getTexto() {
    return this->texto;
}

DtFechaHora Estado::getFechayHora()
{
    return this->fechayHora;
}

//Setter
void Estado::setTexto(string texto) {
    this->texto = texto;
}

//Destructor
Estado::~Estado(){}
