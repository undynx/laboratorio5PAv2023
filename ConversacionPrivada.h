#ifndef CONVERSACIONPRIVADA_H
#define CONVERSACIONPRIVADA_H
#include "Conversacion.h"
#include <string>

using namespace std;

class ConversacionPrivada : public Conversacion{
    private:
        Usuario* primerParticipante;
        Usuario* segundoParticipante;
    public:
        ConversacionPrivada();
        ConversacionPrivada(bool activo, int id, Usuario* primerParticipante, Usuario* segundoParticipante);
        //void MostrarDatosP();
        //void MostrarDatos();
        ~ConversacionPrivada();
};
#endif
