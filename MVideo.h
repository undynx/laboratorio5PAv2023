#ifndef MVIDEO_H
#define MVIDEO_H
#include <string>
#include "DtFechaHora.h"
#include "DtMVideo.h"
#include "Mensaje.h"

using namespace std;

class MVideo : public Mensaje
{
    private:
        string url;
        float duracion;

    public:
        MVideo();
        MVideo(string codigo, int numTelRemitente, DtFechaHora* fechayHora,string url, float duracion);
        string getUrl();
        float getDuracion();
        void setDuracion(float duracion);
        void setUrl(string url);
        virtual DtMVideo* mostrarDatosM();
        ~MVideo();
};
#endif
