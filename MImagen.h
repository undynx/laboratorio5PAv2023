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
        string tamaño;
        string texto;
        map<int,VistoMensaje*> vistoPor;
    public:
        MImagen();
        MImagen(string codigo, int numTelRemitente, DtFechaHora* fechayHora, string url, string formato, string tamaño, string texto);
        string getFormato();
        string getTamaño();
        string getTexto();
        void setFormato(string formato);
        void setTamaño(string tamaño);
        void setTexto(string texto);
        virtual DtMensaje* mostrarDatosM();
        ~MImagen();
};
#endif
