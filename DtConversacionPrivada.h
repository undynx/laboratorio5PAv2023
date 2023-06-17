#ifndef DTCONVERSACIONPRIVADA_H
#define DTCONVERSACIONPRIVADA_H

#include "DtConversacion.h"
#include <string>

using namespace std;

class DtConversacionPrivada : public DtConversacion{
    private:
    int numTel;
    string nombre;
    public:
        DtConversacionPrivada();
        DtConversacionPrivada(int numTel, string nombre);
        int getNumTel();
        string getNombre();
        ~DtConversacionPrivada();
};
#endif