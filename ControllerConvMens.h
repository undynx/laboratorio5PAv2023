#ifndef CONTROLLER_CONVMENS
#define CONTROLLER_CONVMENS
#include <stdlib.h>
#include "InterfaceConvMens.h"

class ControllerConvMens: public InterfaceConvMens
{
    private:
        static ControllerConvMens* instance;
        ControllerConvMens();
        //PseudoAtributos
        //Memoria del Controller
    public:
        static ControllerConvMens* getInstance();
        //Operaciones
};

#endif