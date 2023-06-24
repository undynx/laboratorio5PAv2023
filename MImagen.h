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
        map<int,VistoMensaje*> vistoPor;
    public:
        MImagen();
        MImagen(string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamano, string texto);
        string getFormato();
        string getTamano();
        string getTexto();
        void setFormato(string formato);
        void setTamano(string tamano);
        void setTexto(string texto);
        virtual DtMensaje* mostrarDatosM();
        ~MImagen();
};
#endif
