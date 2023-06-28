#ifndef CONVERSACIONARCHIVADA_H
#define CONVERSACIONARCHIVADA_H
#include "Conversacion.h"
#include "Usuario.h"
#include <string>

using namespace std;

class ConversacionArchivada : public Conversacion{
    private:
        Usuario* primerParticipante;
        Usuario* segundoParticipante;
    public:
        ConversacionArchivada();
        ConversacionArchivada(int idConver, bool activo , Usuario* primerParticipante, Usuario* segundoParticipante);
        Usuario* getOtroParticipante(Usuario* user);
        virtual void mostrarDatosC();
        ~ConversacionArchivada();
};
#endif
