#ifndef MCONTACTO_H
#define MCONTACTO_H
#include "Mensaje.h"
#include "DtFechaHora.h"
#include "Usuario.h"

class MContacto: public Mensaje{
    private:
        DtUsuario contacto;

    public:
        MContacto();
        MContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto);
        DtUsuario getContacto();
        void setContacto(DtUsuario contacto);
        ~MContacto();
};
#endif
