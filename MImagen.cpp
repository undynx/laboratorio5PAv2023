#include "MImagen.h"
//Constructores

MImagen::MImagen() {}

MImagen::MImagen(string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamaño, string texto):Mensaje(codigo, numTelRemitente, fechayHora)
{
    this->url = url;
    this->formato = formato;
    this->tamaño = tamaño;
    this->texto = texto;
}

DtMensaje* MImagen::mostrarDatosM()
{
    //Muestra datos mensaje video. hjm,
}

//Gettes

std::string MImagen::getFormato()
{
    return this->formato;

}

std::string MImagen::getTamaño()
{
    return this->tamaño;

}

std::string MImagen::getTexto()
{
    return this->texto;

}

//Setters

void MImagen::setFormato(string formato)
{
    this->formato = formato;
}

void MImagen::setTamaño(string tamaño)
{
    this->tamaño = tamaño;
}

void MImagen::setTexto(string texto)
{
    this->texto = texto;
}


//Destructor

MImagen::~MImagen(){}


