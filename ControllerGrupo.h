#ifndef CONTROLLERGRUPO_H
#define CONTROLLERGRUPO_H

#include "InterfaceGrupo.h"

class ControllerGrupo: public InterfaceGrupo {
  private:
    static ControllerGrupo *instancia;

  public:
    ControllerGrupo();
    static ControllerGrupo *getInstancia();
    void listarContactosPart(int idGrupo);
    void listarContactosRest(int idGrupo, Usuario *userLoggeado);
    void agregarParticipante(int numTel, int id, Usuario *userLoggeado, DtFechaHora* fechaingreso);
    void agregarAdministrador(int numTel, int id, Usuario *userLoggeado);
    void eliminarParticipante(int numTel, int id,Usuario *userLoggeado);
    ConversacionGrupal *encontrarGrupoPorId(int id);
    ConversacionGrupal *crearGrupo(Usuario *userLoggeado, string nombre, string url, DtFechaHora *fechayHora);
    ~ControllerGrupo();
};

#endif
