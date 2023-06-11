#ifndef DTCONVERSACION_H
#define DTCONVERSACION_H

#include "DtConversacion.h"

class DtConversacion{
    private:
        bool activo;
        int id;
    public:
        DtConversacion();
        DtConversacion(bool activo, int id);
        bool getActivo();
        int getId();
        ~DtConversacion();
};
#endif
