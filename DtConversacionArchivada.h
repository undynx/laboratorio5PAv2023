#ifndef DTCONVERSACIONARCHIVADA_H
#define DTCONVERSACIONARCHIVADA_H
#include "DtConversacion.h"

class DtConversacionArchivada: public DtConversacion{
    private:
       int cantArch;
    public:
        DtConversacionArchivada();
        DtConversacionArchivada(bool activo, int id, int _cantArch);
        int getCantArch();
        ~DtConversacionArchivada();
};
#endif
