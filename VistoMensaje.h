#ifndef VISTOMENSAJE_H
#define VISTOMENSAJE_H
#include <string>
#include "DtFechaHora.h"

using namespace std;

class VistoMensaje {
    private:
        string codigoMsj; //Codigo Mensaje
        int numTelDestinatario; //Numero del destinatario del mensaje.
        DtFechaHora* fecHoraVisto;
        bool visto;
    public:
        VistoMensaje();
        VistoMensaje(string codigoMsj, int numTelDestinatario, DtFechaHora* fecHoraVisto ,bool visto);
        string getCodigo();
        void setCodigo(string codigoMsj);
        void setDestinatario(int numTelDestinatario);
        void setVisto();
        void setFecHoraVisto(DtFechaHora*);
        int getDestinatario();
        bool getVisto();
        DtFechaHora* getfecHoraVisto();
        ~VistoMensaje();
};
#endif