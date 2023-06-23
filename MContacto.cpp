#include "MContacto.h"


//Constructores
MContacto::MContacto(){}

MContacto::MContacto(string codigo, int numTelRemitente, DtFechaHora* fechayHora, DtUsuario contacto):Mensaje(codigo, numTelRemitente, fechayHora){
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
