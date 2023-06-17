#ifndef CONTROLLERGRUPO_H
#define CONTROLLERGRUPO_H

#include <stdlib.h>
#include "InterfaceGrupo.h"

class ControllerGrupo: public InterfaceGrupo {
  private:
    static ControllerGrupo *instancia;

  public:
    ControllerGrupo();
    static ControllerGrupo *getInstancia();
    ~ControllerGrupo();
};

#endif
