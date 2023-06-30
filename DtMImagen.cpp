#include "DtMImagen.h"
//Constructores

DtMImagen::DtMImagen() {}

DtMImagen::DtMImagen(string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamano, string texto):DtMensaje(codigo, numTelRemitente, fechayHora)
{
    this->url = url;
    this->formato = formato;
    this->tamano = tamano;
    this->texto = texto;
}

//Gettes
string DtMImagen::getUrl()
{
    return this->url;

}

string DtMImagen::getFormato()
{
    return this->formato;

}

string DtMImagen::getTamano()
{
    return this->tamano;

}

string DtMImagen::getTexto()
{
    return this->texto;

}

void DtMImagen::getDtM(){}

//Destructor

DtMImagen::~DtMImagen(){}