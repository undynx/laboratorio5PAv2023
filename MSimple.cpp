#include "MSimple.h"
//Constructores

MSimple::MSimple() {}

MSimple::MSimple(string codigo, int numTelRemitente, DtFechaHora* fechayhora, string texto):Mensaje(codigo, numTelRemitente, fechayhora)
{
    this->texto = texto;
}

DtMSimple* MSimple::mostrarDatosM()
{
        DtMSimple* DtmsjSimple = new DtMSimple(this->getCodigo(),this->getNumRemitente(),this->getFechayHora(),this->getTexto());
        DtMensaje *Dtmsj = DtmsjSimple;
        DtmsjSimple = dynamic_cast<DtMSimple*>(Dtmsj);

        return DtmsjSimple;
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


