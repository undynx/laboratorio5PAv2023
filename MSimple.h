#ifndef MSIMPLE_H
#define MSIMPLE_H
#include <string>
#include "DtFechaHora.h"
#include "DtMSimple.h"
#include "Mensaje.h"

using namespace std;

class MSimple : public Mensaje
{
    private:
        string texto;

    public:
        MSimple();
        MSimple(string codigo, int numTelRemitente, DtFechaHora* fechayhora, string texto);
        string getTexto();
        void setTexto(std::string texto);
        virtual DtMSimple* mostrarDatosM();
        ~MSimple();
};
#endif
