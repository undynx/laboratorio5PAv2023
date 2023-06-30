#include "MImagen.h"
//Constructores

MImagen::MImagen() {}

MImagen::MImagen(string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamano, string texto):Mensaje(codigo, numTelRemitente, fechayHora)
{
    this->url = url;
    this->formato = formato;
    this->tamano = tamano;
    this->texto = texto;
}

//Gettes
string MImagen::getUrl()
{
    return this->url;

}

string MImagen::getFormato()
{
    return this->formato;

}

string MImagen::getTamano()
{
    return this->tamano;

}

string MImagen::getTexto()
{
    return this->texto;

}

DtMImagen* MImagen::mostrarDatosM()
{
        DtMImagen* DtmsjImagen = new DtMImagen(this->getCodigo(),this->getNumRemitente(),this->getFechayHora(),this->getUrl(),this->getFormato(),this->getTamano(),this->getTexto());
        DtMensaje *Dtmsj = DtmsjImagen;
        DtmsjImagen = dynamic_cast<DtMImagen*>(Dtmsj);

        return DtmsjImagen;
}

//Setters
void MImagen::setUrl(string url)
{
    this->url = url;
}

void MImagen::setFormato(string formato)
{
    this->formato = formato;
}

void MImagen::setTamano(string tamano)
{
    this->tamano = tamano;
}

void MImagen::setTexto(string texto)
{
    this->texto = texto;
}


//Destructor

MImagen::~MImagen(){}


