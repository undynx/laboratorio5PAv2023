#ifndef DTMVideo_H
#define DTMVideo_H
#include <string>
#include "DtFechaHora.h"
#include "DtMensaje.h"

using namespace std;

class DtMVideo : public DtMensaje
{
    private:
        string url;
        float duracion;

    public:
        DtMVideo();
        DtMVideo(string codigo, int numTelRemitente, DtFechaHora* fechayHora,string url, float duracion);
        string getUrl();
        float getDuracion();
        virtual void getDtM();
        ~DtMVideo();
};
#endif