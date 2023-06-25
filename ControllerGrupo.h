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
    void listarContactosRest(int idGrupo);
    void agregarParticipante(int numTel, int id, DtFechaHora* fechaingreso);
    void agregarAdministrador(int numTel, int id);
    void eliminarParticipante(int numTel, int id);
    ConversacionGrupal *encontrarGrupoPorId(int id);
    int crearGrupo(string nombre, string url, DtFechaHora *fechayHora);
    ~ControllerGrupo();
};

#endif
