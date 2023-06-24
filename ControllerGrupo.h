#ifndef CONTROLLERGRUPO_H
#define CONTROLLERGRUPO_H

#include <stdlib.h>
#include <map>
#include <list>
#include "InterfaceGrupo.h"
#

class ControllerGrupo: public InterfaceGrupo {
  private:
    static ControllerGrupo *instancia;
    map<int, Usuario*> participantes;
    map<int, Usuario*> restantes;

  public:
    ControllerGrupo();
    static ControllerGrupo *getInstancia();
     void listarContactosPart(DtUsuario* part);
     void listarContactosRest(DtUsuario* Rest);
     void agregarParticipante(Usuario* agregarP);
     void quitarParticipante(Usuario* quitarP);
     void ingresoGrupo(ConversacionGrupal* grupo);
    ~ControllerGrupo();
};

#endif
