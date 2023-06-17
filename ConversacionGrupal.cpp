#include "ConversacionGrupal.h"
#include "DtConversacionGrupal.h"

//Constructores
ConversacionGrupal::ConversacionGrupal(){}

ConversacionGrupal::ConversacionGrupal(string nombre, string imagen, DtFechaHora fechayHora, bool activo, int id){
    this-> nombre=nombre;
    this-> imagen=imagen;
    this-> fechayHora=fechayHora;
}

//Gettes
string ConversacionGrupal::getNombre(){
    return this-> nombre=nombre;
}
string ConversacionGrupal::getImagen(){
    return this-> imagen=imagen;
}
DtFechaHora ConversacionGrupal::getFechayHora(){
    return this-> fechayHora=fechayHora;
}

//Setters
void ConversacionGrupal::setNombre(string nombre){
    this->nombre=nombre;
}
void ConversacionGrupal::setImagen(string imagen){
    this->imagen=imagen;
}
void ConversacionGrupal::setFechayHora(DtFechaHora fechayHora){
    this->fechayHora=fechayHora;
}
//Metodos
void MostrarConverG(){
    
    //hay que desarrollar
}

//Destructor
ConversacionGrupal::~ConversacionGrupal(){}