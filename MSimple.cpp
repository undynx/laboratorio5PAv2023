#include "MSimple.h"
//Constructores

MSimple::MSimple() {}

MSimple::MSimple(string codigo, DtFechaHora* fechayhora, string texto):Mensaje(codigo, fechayhora)
{
    this->texto = texto;
}

void MSimple::MostrardatosM()
{
    //Muestra datos mensaje video. hjm,
}

//Gettes

std::string MSimple::getTexto()
{
    return this->texto;
}


//Setters

void MSimple::setTexto(std::string texto)
{
    this->texto = texto;
}


//Destructor

MSimple::~MSimple(){}


