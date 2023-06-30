#include "ControllerGrupo.h"

ControllerGrupo *ControllerGrupo::instancia = NULL;

ControllerGrupo::ControllerGrupo(){}

ControllerGrupo *ControllerGrupo::getInstancia() {
  if (instancia == NULL)
  {
    instancia = new ControllerGrupo();
  }
  return instancia;
}

void ControllerGrupo::listarContactosPart(int idGrupo)
{
  ConversacionGrupal *grupo = encontrarGrupoPorId(idGrupo);
  map<int, Usuario*> colParticipantes = grupo->getListaParticipantes();
  for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
  {
    cout << it->second->getNombre() << ": " << it->second->getNumTel() << endl;
  }


}

void ControllerGrupo::listarContactosRest(int idGrupo)
{
  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *userLoggeado = cSesion->getUserLoggeado();

  ConversacionGrupal *grupo = encontrarGrupoPorId(idGrupo);

  map<int, Usuario *> colRestantes = userLoggeado->getListaContactos();
  map<int, Usuario*> colParticipantes = grupo->getListaParticipantes();
  for (auto it = colRestantes.begin(); it != colRestantes.end(); it++)
  {
    if (colParticipantes.find(it->first) == colParticipantes.end())
    {
      cout << it->second->getNombre() << ": " << it->second->getNumTel() << endl;
    }
    
  }

}

void ControllerGrupo::agregarParticipante(int numTel, int id, DtFechaHora* fechaIngreso)
{
  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *userLoggeado = cSesion->getUserLoggeado();
  Usuario* participante = userLoggeado->getContacto(numTel);
  Conversacion *conver;

  if(participante==NULL)
  {
     cout << "ERROR: El número ingresado no existe en su lista de contactos" << endl;
  }
  else
  {
    ConversacionGrupal* cg = encontrarGrupoPorId(id);
    conver = cg;
    cg = dynamic_cast<ConversacionGrupal *>(conver);

    if(cg==NULL){
      cout << "ERROR: El id ingresado no existe en su lista de conversaciones" << endl;
    }
    else
    {
      if(cg->perteneceAdministrador(userLoggeado->getNumTel()))
      {
        if(cg->perteneceParticipante(numTel)){
          cout << " ERROR: Este usuario ya es participante del grupo" << endl;
        } else {
          cg->setParticipante(participante);
          cg->setFechaIngresoParticipante(numTel, fechaIngreso);
          participante->setConver(cg);
          map<string,Mensaje*> colMensajesConverGrup = cg->getListaMensajes();
          for (auto it = colMensajesConverGrup.begin(); it != colMensajesConverGrup.end(); it++)
          {
              if(it->second->getFechayHora()->esIgualQue(fechaIngreso))
              {
                it->second->setVistoPor(new VistoMensaje(numTel,NULL,false));
              }
          }
          cout << "Se agregó participante al grupo" << endl;
        }
      }
      else
      {
        cout << "ERROR: Para realizar esta acción debe ser administrador del grupo" << endl;
      }
    }
  }

}

void ControllerGrupo::eliminarParticipante(int numTel, int id)
{

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *userLoggeado = cSesion->getUserLoggeado();
  Usuario* participante = userLoggeado->getContacto(numTel);

  if(participante==NULL)
  {
     cout << "ERROR: El número ingresado no existe en su lista de contactos" << endl;
  }
  else
  {
    ConversacionGrupal* cg = encontrarGrupoPorId(id);

    if(cg==NULL){
      cout << "ERROR: El id ingresado no existe en su lista de conversaciones" << endl;
    }
    else
    {
        cg->eliminarParticipante(numTel);
        cout << "Se eliminó al participante del grupo" << endl;
    }

  }

}

void ControllerGrupo::agregarAdministrador(int numTel, int id)
{

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *userLoggeado = cSesion->getUserLoggeado();
  Usuario* administrador = userLoggeado->getContacto(numTel);

  if(administrador==NULL)
  {
     cout << "ERROR: El número ingresado no existe en su lista de contactos" << endl;
  }
  else
  {
    ConversacionGrupal* cg = encontrarGrupoPorId(id);

    if(cg==NULL){
      cout << "ERROR: El id ingresado no existe en su lista de conversaciones" << endl;
    }
    else
    {

      if(cg->perteneceAdministrador(userLoggeado->getNumTel()))
      {
          if(cg->perteneceAdministrador(numTel)){
            cout << "ERROR: Este usuario ya es administrador del grupo" << endl;
          }
          else if(!cg->perteneceParticipante(numTel)){
            cout << "ERROR: El usuario no es participante del grupo" << endl;
          }
          else
          {
          cg->setAdministrador(administrador);
          cout << "Usuario agregado correctamente como administrador del grupo" << endl;
        }
      }
      else
      {
        cout << "ERROR: Para realizar esta acción debe ser administrador del grupo" << endl;
      }
    }
  }
}

int ControllerGrupo::crearGrupo(string nombre, string url, DtFechaHora* fechayHora)
{
  int id = rand() % 100 + 1;
  int contacto;
  int opt;
  bool salir = false;

  ConversacionGrupal* cg = new ConversacionGrupal(id, true, nombre, url, fechayHora);
  Conversacion* conver = cg;
  cg = dynamic_cast<ConversacionGrupal*>(conver);

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *userLoggeado = cSesion->getUserLoggeado();

  cg->setAdministrador(userLoggeado);
  cg->setParticipante(userLoggeado);
  cg->setFechaIngresoParticipante(userLoggeado->getNumTel(), fechayHora);
  // Agrego la conversacion a la lista de conversaciones del usuario
  userLoggeado->setConver(cg);
  ControllerConvMens *ccm = ControllerConvMens::getInstancia();
  // Agrego la conversacion a la lista de conversaciones del sistema
  ccm->setConversacionColSis(cg, id);

  cout << "Grupo creado con el id: " << id <<endl;

  do{
    cout << "\n----------------------------" << endl;
    cout << "CONTACTOS" << endl;
    listarContactosRest(id);
    cout << "----------------------------" << endl;
    cout << "PARTICIPANTES" << endl;
    listarContactosPart(id);
    cout << "----------------------------" << endl;
    cout << "Ingresa el numero del contacto a ingresar o quitar: " << endl;
    cin >> contacto;
    if(userLoggeado->getContacto(contacto) == NULL){
      cout << "  ERROR: No tenes ningun contacto con ese numero" << endl;
    }
    else
    {
      if(cg->perteneceParticipante(contacto)){
        eliminarParticipante(contacto, id);
        cout << "Participante eliminado con éxito" << endl;
      }else {
        agregarParticipante(contacto, id, fechayHora);
        cout << "Participante agregado con éxito" << endl;
      }
      cout << "Deseas seguir agregando participantes?" << endl;
      cout << "  1) SI" << endl;
      cout << "  2) NO" << endl;
      cin >> opt;
      if (opt == 2)
      {
        salir = true;
      }
    }

  } while (!salir);

  return id;
}

ConversacionGrupal* ControllerGrupo::encontrarGrupoPorId(int id)
{
  ControllerConvMens *ccm = ControllerConvMens::getInstancia();
  ConversacionGrupal *cg;
  Conversacion *conver = ccm->getConverSis(id);
  cg = dynamic_cast<ConversacionGrupal *>(conver);
  return cg;
}
