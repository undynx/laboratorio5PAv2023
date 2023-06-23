#include "MVideo.h"
//Constructores

MVideo::MVideo() {}

MVideo::MVideo(string codigo, int numTelRemitente, DtFechaHora* fechayhora,string url, float duracion):Mensaje(codigo, numTelRemitente,fechayhora)
{
    this->url = url;
    this->duracion = duracion;
}

void MVideo::MostrardatosM()
{
    //Muestra datos mensaje video. hjm,
}

//Gettes

float MVideo::getDuracion()
{
    return this->duracion;
}


//Setters

void MVideo::setDuracion(float duracion)
{
    this->duracion = duracion;
}


//Destructor

MVideo::~MVideo(){}


