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
    return this-> nombre;
}
string ConversacionGrupal::getImagen(){
    return this-> imagen;
}
DtFechaHora* ConversacionGrupal::getFechayHora(){
    return this-> fechayHora;
}

Usuario* ConversacionGrupal::getParticipante(int numTel){

 if (colParticipantes.find(numTel) != colParticipantes.end())
    {
          return colParticipantes.at(numTel);
    }
    return NULL;
}

Usuario* ConversacionGrupal::getAdministrador(int numTel)
{
    if (colAdministradores.find(numTel) != colAdministradores.end())
    {
          return colAdministradores.at(numTel);
    }
    return NULL;
}

DtFechaHora* ConversacionGrupal::getFechaIngresoParticipante(int numTel){

     if (colFechasIngresosParticipantes.find(numTel) != colFechasIngresosParticipantes.end())
    {
          return colFechasIngresosParticipantes.at(numTel);
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

void ConversacionGrupal::setFechaIngresoParticipante(int numTel,DtFechaHora* fechaIngreso)
{
    this->colFechasIngresosParticipantes.insert({numTel, fechaIngreso});
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

map<int, DtFechaHora*> ConversacionGrupal::getListaIngresosParticipantes()
{
    return this->colFechasIngresosParticipantes;
}

void ConversacionGrupal::mostrarDatosC(){
    
    //hay que desarrollar
}

void ConversacionGrupal::eliminarParticipante(int numTel)
{
    auto iter = this->colParticipantes.find(numTel);
    if(iter != this->colParticipantes.end()){
        this->colParticipantes.erase(numTel);
    }
}

//Destructor
ConversacionGrupal::~ConversacionGrupal(){}
