#include "MVideo.h"
//Constructores

MVideo::MVideo() {}

MVideo::MVideo(string codigo, int numTelRemitente, DtFechaHora* fechayhora,string url, float duracion):Mensaje(codigo, numTelRemitente,fechayhora)
{
    this->url = url;
    this->duracion = duracion;
}

//Gettes

string MVideo::getUrl()
{
    return this->url;

}

float MVideo::getDuracion()
{
    return this->duracion;
}


//Setters
void MVideo::setUrl(string url)
{
    this->url = url;
}

void MVideo::setDuracion(float duracion)
{
    this->duracion = duracion;
}

//Destructor

MVideo::~MVideo(){}


