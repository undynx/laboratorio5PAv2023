#ifndef DTMIMAGEN_H
#define DTMIMAGEN_H
#include <string>
#include "DtFechaHora.h"
#include "DtMensaje.h"

using namespace std;

class DtMImagen : public DtMensaje
{
    private:
        string url;
        string formato;
        string tamano;
        string texto;

    public:
        DtMImagen();
        DtMImagen (string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamano, string texto);
        string getUrl();
        string getFormato();
        string getTamano();
        string getTexto();
        virtual void getDtM();
        ~DtMImagen();
};
#endif
