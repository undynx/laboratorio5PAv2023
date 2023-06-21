#include "MContacto.h"


//Constructores
MContacto::MContacto(){}

MContacto::MContacto(string codigo, DtFechaHora* fechayHora, DtUsuario contacto):Mensaje(codigo, fechayHora){
    this->contacto = contacto;
}

//Metodos
void MContacto::mostrarDatos(){

}
MContacto MContacto::borrar(DtMensaje m){
    
}
DtMensaje MContacto::seleccionar(){

}
MContacto::~MContacto(){};
