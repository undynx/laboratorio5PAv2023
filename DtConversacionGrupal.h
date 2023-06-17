#ifndef DTCONVERSACIONGRUPAL_H
#define DTCONVERSACIONGRUPAL_H

#include "DtConversacion.h"
#include <string>

using namespace std;

class DtConversacionGrupal : public DtConversacion{
    private:
    int numTel;
    string nombre;
    public:
        DtConversacionGrupal();
        DtConversacionGrupal(bool activo, int id, string nombre);
        DtConversacionGrupal(string nombre);
        string getNombre();
        ~DtConversacionGrupal();
};
#endif