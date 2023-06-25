#ifndef CONTROLLERGRUPO_H
#define CONTROLLERGRUPO_H

#include <stdlib.h>
#include <map>
#include <list>
#include "InterfaceGrupo.h"

class ControllerGrupo: public InterfaceGrupo {
  private:
    static ControllerGrupo *instancia;
    map<int, Usuario*> participantes;
    map<int, Usuario*> restantes;

  public:
    ControllerGrupo();
    static ControllerGrupo *getInstancia();
    void listarContactosPart(int idGrupo);
    void listarContactosRest(int idGrupo, Usuario *userLoggeado);
    void agregarParticipante(int numTel, int id, Usuario *userLoggeado);
    void agregarAdministrador(int numTel, int id, Usuario *userLoggeado);
    void quitarParticipante(int numTel, int id);
    ConversacionGrupal *encontrarGrupoPorId(int id);
    ConversacionGrupal *crearGrupo(Usuario *userLoggeado, string nombre, string url, DtFechaHora *fechayHora);
    ~ControllerGrupo();
};

#endif
