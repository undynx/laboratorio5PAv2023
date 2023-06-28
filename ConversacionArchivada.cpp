#include "ConversacionArchivada.h"

//Constructores
ConversacionArchivada::ConversacionArchivada(){}

ConversacionArchivada::ConversacionArchivada(int idConver, bool activo, Usuario* primerParticipante, Usuario* segundoParticipante) : Conversacion(idConver, activo){
    this->primerParticipante = primerParticipante;
    this->segundoParticipante = segundoParticipante;
}


//Getters
Usuario* ConversacionArchivada::getOtroParticipante(Usuario* user){

    if(this->primerParticipante==user)
    {
        return this->segundoParticipante;
    }else
    {
        return this->primerParticipante;
    }

}
//Gettes

//Setters

//Destructor
ConversacionArchivada::~ConversacionArchivada(){}


//Metodos
void ConversacionArchivada::mostrarDatosC(){}