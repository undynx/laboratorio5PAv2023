#ifndef MIMAGEN_H
#define MIMAGEN_H
#include <string>
#include "DtFechaHora.h"
#include "Mensaje.h"

using namespace std;

class MImagen : public Mensaje
{
    private:
        string url;
        string formato;
        string tamano;
        string texto;

    public:
        MImagen();
        MImagen(string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamano, string texto);
        string getUrl();
        string getFormato();
        string getTamano();
        string getTexto();
        void setUrl(string url);
        void setFormato(string formato);
        void setTamano(string tamano);
        void setTexto(string texto);
        ~MImagen();
};
#endif
