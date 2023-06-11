#ifndef CONTROLLERGRUPO
#define CONTROLLERGRUPO

#include <stdlib.h>
#include "InterfaceGrupo.h"

class ControllerGrupo: public InterfaceGrupo {
  private:
    static ControllerGrupo *instance;
  public:
    ControllerGrupo();
};

#endif
