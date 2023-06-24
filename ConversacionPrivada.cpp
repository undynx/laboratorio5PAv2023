#include "ConversacionPrivada.h"

//Constructores
ConversacionPrivada::ConversacionPrivada(){}

ConversacionPrivada::ConversacionPrivada(int idConver, bool activo, Usuario* primerParticipante, Usuario* segundoParticipante) : Conversacion(idConver, activo){
    this->primerParticipante = primerParticipante;
    this->segundoParticipante = segundoParticipante;
}


//Getters
Usuario* ConversacionPrivada::getOtroParticipante(Usuario* user){

    Usuario* user2 = new Usuario();

    if(this->primerParticipante==user)
    {
        return this->segundoParticipante;
    }else
    {
        return this->primerParticipante;
    }

}

//Metodos
void ConversacionPrivada::mostrarDatosC(){

}



//Destructor
ConversacionPrivada::~ConversacionPrivada(){}
