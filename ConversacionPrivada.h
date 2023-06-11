#ifndef CONVERSACIONPRIVADA_H
#define CONVERSACIONPRIVADA_H

#include "Conversacion.h"
#include <string>

using namespace std;

class ConversacionPrivada : public Conversacion{
    private:
    public:
        ConversacionPrivada();
        ConversacionPrivada(bool activo, int id );
        bool getActivo();
        void setActivo(bool);
        int getId();
        void setId(int);        
        void MostrarDatosP();
        void MostrarDatos();
        ~ConversacionPrivada();
};
#endif
