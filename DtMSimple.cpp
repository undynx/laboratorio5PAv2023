#include "DtMSimple.h"
//Constructores

DtMSimple::DtMSimple() {}

DtMSimple::DtMSimple(string codigo, int numTelRemitente, DtFechaHora* fechayhora, string texto):DtMensaje(codigo, numTelRemitente, fechayhora)
{
    this->texto = texto;
}

void DtMSimple::getDtM(){}

//Gettes

std::string DtMSimple::getTexto()
{
    return this->texto;
}

//Destructor

DtMSimple::~DtMSimple(){}

