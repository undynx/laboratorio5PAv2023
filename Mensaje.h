#ifndef MENSAJE_H
#define MENSAJE_H
#include <string>
#include <map>
#include "DtFechaHora.h"
#include "DtMensaje.h"
#include "VistoMensaje.h"

using namespace std;

class Mensaje {
    private:
        string codigo;
        int numTelRemitente; //Numero del usuario que envió el mensaje.
        DtFechaHora* fechayHora; 
        map<int,VistoMensaje*> vistoPor;
    public:
        Mensaje();
        Mensaje(string codigo,int numTelRemitente ,DtFechaHora* fechayHora);
        string getCodigo();
        void setCodigo(string);
        int getNumRemitente();
        DtFechaHora* getFechayHora();
        void setVistoPor(VistoMensaje* vistoPor);
        VistoMensaje* getVistoPor(int numVistoPor);
        map<int,VistoMensaje*> getListaVistoPor();
        //DtMensaje delete(DtMensaje); ??
        //DtMensaje seleccionar();
        virtual ~Mensaje();
};
#endif