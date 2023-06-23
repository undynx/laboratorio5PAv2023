#include "ConversacionPrivada.h"

//Constructores
ConversacionPrivada::ConversacionPrivada(){}

ConversacionPrivada::ConversacionPrivada(bool activo, int id, Usuario* primerParticipante, Usuario* segundoParticipante) : Conversacion(Conversacion::getActivo(), Conversacion::getId()){
    this->primerParticipante = primerParticipante;
    this->segundoParticipante = segundoParticipante;
}


/*
//Metodos
void ConversacionPrivada::MostrarDatosP(){

}
void ConversacionPrivada::MostrarDatos(){
    
}*/

//Destructor
ConversacionPrivada::~ConversacionPrivada(){}
