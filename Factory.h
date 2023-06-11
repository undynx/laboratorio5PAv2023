#ifndef FACTORY_H
#define FACTORY_H

#include "InterfaceConvMens.h"
#include "InterfaceUsuario.h"

class Factory {
  private:
    static Factory *instance;
    Factory();
  public:
    static Factory *getInstancia();
    InterfaceConvMens *getInterfaceConvMens();
    InterfaceUsuario *getInterfaceUsuario();
    ~Factory();
};

#endif;
