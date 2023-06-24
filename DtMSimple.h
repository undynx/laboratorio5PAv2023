#ifndef DTMSIMPLE_H
#define DTMSIMPLE_H
#include <string>
#include "DtFechaHora.h"
#include "DtMensaje.h"

using namespace std;

class DtMSimple : public DtMensaje
{
    private:
        string texto;
    public:
        DtMSimple();
        DtMSimple(string codigo, int numTelRemitente, DtFechaHora* fechayhora, string texto);
        string getTexto();
        virtual void getDtM();
        ~DtMSimple();
};
#endif
