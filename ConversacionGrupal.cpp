#include "ConversacionGrupal.h"
#include "DtConversacionGrupal.h"

//Constructores
ConversacionGrupal::ConversacionGrupal(){}

ConversacionGrupal::ConversacionGrupal(int id, bool activo, string nombre, string imagen, DtFechaHora* fechayHora) : Conversacion(id, activo){
    this->nombre = nombre;
    this->imagen = imagen;
    this->fechayHora = fechayHora;
}

//Gettes
string ConversacionGrupal::getNombre(){
    return this-> nombre=nombre;
}
string ConversacionGrupal::getImagen(){
    return this-> imagen=imagen;
}
DtFechaHora* ConversacionGrupal::getFechayHora(){
    return this-> fechayHora=fechayHora;
}

Usuario* ConversacionGrupal::getParticipante(int numTel){

 if (colParticipantes.find(numTel) != colParticipantes.end())
    {
          return colParticipantes.at(numTel);
    }
    return NULL;
}

//Setters
void ConversacionGrupal::setNombre(string nombre){
    this->nombre=nombre;
}
void ConversacionGrupal::setImagen(string imagen){
    this->imagen=imagen;
}
void ConversacionGrupal::setFechayHora(DtFechaHora* fechayHora){
    this->fechayHora=fechayHora;
}

//Metodos

bool ConversacionGrupal::perteneceParticipante(int numTel)
{
    if (colParticipantes.find(numTel) != colParticipantes.end())
    {
          return true;
    }
    return false;
}

bool ConversacionGrupal::perteneceAdministrador(int numTel)
{
    if (colAdministradores.find(numTel) != colAdministradores.end())
    {
          return true;
    }
    return false;
}

map <int, Usuario*> ConversacionGrupal::getListaParticipantes()
{
    return this->colParticipantes;
}

void ConversacionGrupal::mostrarDatosC(){
    
    //hay que desarrollar
}

Usuario* ConversacionGrupal::getAdministrador(int numTel)
{
    if (colAdministradores.find(numTel) != colAdministradores.end())
    {
          return colAdministradores.at(numTel);
    }
    return NULL;
}

void ConversacionGrupal::setParticipante(Usuario *u)
{
    // Agrego al usuario que viene por parametro "u" a la lista de participantes de la conversacion
    this->colParticipantes.insert({u->getNumTel(), u});
}

void ConversacionGrupal::setAdministrador(Usuario* administrador)
{
    //Agrego al usuario que viene por parametro "administrador" a la lista de participantes de la conversacion
    this->colAdministradores.insert({administrador->getNumTel(), administrador});
}


//Destructor
ConversacionGrupal::~ConversacionGrupal(){}
