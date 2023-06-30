#ifndef DtMContacto_H
#define DtMContacto_H
#include "Mensaje.h"
#include "DtFechaHora.h"
#include "DtMensaje.h"
#include "DtUsuario.h"

class DtMContacto: public DtMensaje{
    private:
        DtUsuario contacto;

    public:
        DtMContacto();
        DtMContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto);
        DtUsuario getContacto();
        virtual void getDtM();
        ~DtMContacto();
};
#endif
