#ifndef INTERFACEGRUPO_H
#define INTERFACEGRUPO_H
#include <stdlib.h>
#include <map>
#include "Usuario.h"
#include "ConversacionGrupal.h"
#include "ControllerSesion.h"
#include "ControllerUsuario.h"
#include "ControllerConvMens.h"

using namespace std;
class InterfaceGrupo{
  public:
    virtual void listarContactosPart(int idGrupo) = 0;
    virtual void listarContactosRest(int idGrupo) = 0;
    virtual void agregarParticipante(int numTel, int id, DtFechaHora* fechaingreso) = 0;
    virtual void agregarAdministrador(int numTel, int id) = 0;
    virtual void eliminarParticipante(int numTel, int id) = 0;
    virtual ConversacionGrupal* encontrarGrupoPorId(int id) = 0;
    virtual int crearGrupo(string nombre, string url, DtFechaHora* fechayHora) = 0;
};

#endif
