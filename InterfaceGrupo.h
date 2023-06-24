#ifndef INTERFACEGRUPO_H
#define INTERFACEGRUPO_H

#include "DtUsuario.h"
#include "Usuario.h"
#include "ConversacionGrupal.h"

using namespace std;
class InterfaceGrupo{
  public:
    virtual void listarContactosPart(DtUsuario* part) = 0;
    virtual void listarContactosRest(DtUsuario* Rest) = 0;
    virtual void agregarParticipante(Usuario* agregarP) = 0;
    virtual void quitarParticipante(Usuario* quitarP) = 0;
    virtual void ingresoGrupo(ConversacionGrupal* grupo) = 0;


};

#endif
