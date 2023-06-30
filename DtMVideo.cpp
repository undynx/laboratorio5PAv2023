#include "DtMVideo.h"
//Constructores

DtMVideo::DtMVideo() {}

DtMVideo::DtMVideo(string codigo, int numTelRemitente, DtFechaHora* fechayhora,string url, float duracion):DtMensaje(codigo, numTelRemitente,fechayhora)
{
    this->url = url;
    this->duracion = duracion;
}

//Gettes

void DtMVideo::getDtM(){}

string DtMVideo::getUrl()
{
    return this->url;

}

float DtMVideo::getDuracion()
{
    return this->duracion;
}

//Destructor

DtMVideo::~DtMVideo(){}