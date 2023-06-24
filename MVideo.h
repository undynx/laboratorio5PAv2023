#ifndef MVIDEO_H
#define MVIDEO_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MVideo : public Mensaje
{
    private:
        string url;
        float duracion;
        map<int,VistoMensaje*> vistoPor;
    public:
        MVideo();
        MVideo(string codigo, int numTelRemitente, DtFechaHora* fechayHora,string url, float duracion);
        float getDuracion();
        void setDuracion(float duracion);
        virtual DtMensaje* mostrarDatosM();
        ~MVideo();
};
#endif
