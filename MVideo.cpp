#include "MVideo.h"
//Constructores

MVideo::MVideo() {}

MVideo::MVideo(std::string codigo, DtFechaHora fechayhora, float duracion):Mensaje(codigo, fechayhora)
{

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


