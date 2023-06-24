#ifndef CONVERSACIONPRIVADA_H
#define CONVERSACIONPRIVADA_H
#include "Conversacion.h"
#include "Usuario.h"
#include <string>

using namespace std;

class ConversacionPrivada : public Conversacion{
    private:
        Usuario* primerParticipante;
        Usuario* segundoParticipante;
    public:
        ConversacionPrivada();
        ConversacionPrivada(int idConver, bool activo , Usuario* primerParticipante, Usuario* segundoParticipante);
        Usuario* getOtroParticipante(Usuario* user);
        virtual void mostrarDatosC();
        ~ConversacionPrivada();
};
#endif
