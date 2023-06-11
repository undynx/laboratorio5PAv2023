#include "ControllerConvMens.h"

ControllerConvMens* ControllerConvMens::instance=NULL;

ControllerConvMens::ControllerConvMens(){}

ControllerConvMens* ControllerConvMens::getInstance() {
    if(instance==NULL){
        instance = new ControllerConvMens();
    }
    
    return instance;
}
