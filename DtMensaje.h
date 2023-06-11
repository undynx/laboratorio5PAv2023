#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <string>
#include "DtFechaHora.h"

using namespace std;

class DtMensaje{
    private:
        string id;
        DtFechaHora fechayHora;
        bool visto;
    public:
        DtMensaje();
        DtMensaje(string id, DtFechaHora fechayHora, bool visto);
        string getId();
        DtFechaHora getFechayHora();
        bool getVisto();
        ~DtMensaje();
};
#endif
