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
     void listarContactosPart(ConversacionGrupal* grupo);
     void listarContactosRest(ConversacionGrupal* grupo);
     void agregarParticipante(int numTel, int id);
     void agregarAdministrador(int numTel, int id);
     void quitarParticipante(int numTel, int id);
     ConversacionGrupal* encontrarGrupoPorId(int id);
     ConversacionGrupal* crearGrupo(string nombre, string url, DtFechaHora* fechayHora);
    ~ControllerGrupo();
};

#endif
