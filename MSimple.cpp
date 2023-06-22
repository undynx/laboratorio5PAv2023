#include "MSimple.h"
//Constructores

MSimple::MSimple() {}

MSimple::MSimple(string codigo, int numTelRemitente, DtFechaHora* fechayhora, string texto):Mensaje(codigo, numTelRemitente, fechayhora)
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


