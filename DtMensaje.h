#ifndef DTMENSAJE_H
#define DTMENSAJE_H
#include <string>
#include "DtFechaHora.h"

using namespace std;

class DtMensaje{
    private:
        string codigo;
        int numRemitente;
        DtFechaHora* fechayHora;
        
    public:
        DtMensaje();
        DtMensaje(string codigo, int numRemitente,DtFechaHora* fechayHora);
        string getCodigo();
        DtFechaHora* getFechayHora();
        virtual void getDtM()=0;
        int getNumRemitente();
        virtual ~DtMensaje();
};
#endif
