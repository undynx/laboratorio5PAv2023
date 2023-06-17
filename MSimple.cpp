#include "MSimple.h"
//Constructores

MSimple::MSimple() {}

MSimple::MSimple(std::string codigo, DtFechaHora fechayhora, std::string texto):Mensaje(codigo, fechayhora)
{

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


