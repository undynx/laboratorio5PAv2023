#ifndef MENSAJE_H
#define MENSAJE_H
#include <string>
#include "DtFechaHora.h"
#include "DtMensaje.h"

using namespace std;

class Mensaje {
    private:
        string codigo;
        int numTelRemitente; //Numero del usuario que envió el mensaje.
        DtFechaHora* fechayHora; 

    public:
        Mensaje();
        Mensaje(string codigo,int numTelRemitente ,DtFechaHora* fechayHora);
        string getCodigo();
        void setCodigo(string);
        int getNumRemitente();
        DtFechaHora* getFechayHora();
        void MostrardatosM();
        //DtMensaje delete(DtMensaje); ??
        DtMensaje seleccionar();
        ~Mensaje();
};
#endif
