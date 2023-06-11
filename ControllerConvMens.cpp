#include "ControllerConvMens.h"

ControllerConvMens* ControllerConvMens::instance=nullptr;

ControllerConvMens::ControllerConvMens(){}

ControllerConvMens* ControllerConvMens::getInstance()
{
    if(instance==nullptr)
    {
        instance = new ControllerConvMens();
    }
return instance;
}