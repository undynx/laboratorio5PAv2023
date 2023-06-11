#include <stdlib.h>
#include "ControllerConvMens.h"

ControllerConvMens* ControllerConvMens::instance=NULL;

ControllerConvMens::ControllerConvMens(){}

ControllerConvMens* ControllerConvMens::getInstance()
{
    if(instance==nullptr)
    {
        instance = new ControllerConvMens();
    }
return instance;
}
