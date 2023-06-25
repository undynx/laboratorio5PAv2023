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

void ControllerGrupo::listarContactosRest(int idGrupo, Usuario *userLoggeado)
{
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

void ControllerGrupo::agregarParticipante(int numTel, int id, Usuario* userLoggeado)
{
  Usuario* participante = userLoggeado->getContacto(numTel);
  ConversacionGrupal* cg = encontrarGrupoPorId(id);
  if(cg->perteneceParticipante(numTel)){
    cout << "  ERROR: Este usuario ya es participante del grupo" << endl;
  } else {
    cg->setParticipante(participante);
  }
}

void ControllerGrupo::quitarParticipante(int numTel, int id)
{
  ConversacionGrupal *cg = encontrarGrupoPorId(id);
  cg->eliminarParticipante(numTel);
}

void ControllerGrupo::agregarAdministrador(int numTel, int id, Usuario* userLoggeado)
{
  ControllerSesion* cs = ControllerSesion::getInstancia();
  Usuario* user = cs->getUserLoggeado();
  Usuario* administrador = user->getContacto(numTel);
  ConversacionGrupal* cg = encontrarGrupoPorId(id);
  cg->setAdministrador(administrador);
}

ConversacionGrupal *ControllerGrupo::crearGrupo(Usuario *userLoggeado, string nombre, string url, DtFechaHora *fechayHora)
{
  int id = rand() % 100 + 1;
  int contacto;
  int opt;
  bool salir = false;

  ConversacionGrupal* cg = new ConversacionGrupal(id, true, nombre, url, fechayHora);
  Conversacion* conver = cg;
  cg = dynamic_cast<ConversacionGrupal*>(conver);

  cg->setAdministrador(userLoggeado);
  cg->setParticipante(userLoggeado);
  // Agrego la conversacion a la lista de conversaciones del usuario
  userLoggeado->setConver(cg);
  ControllerConvMens *ccm = ControllerConvMens::getInstancia();
  // Agrego la conversacion a la lista de conversaciones del sistema
  ccm->setConversacionColSis(cg, id);

  cout << "Grupo creado con el id: " << id <<endl;

  do{
    cout << "\n----------------------------" << endl;
    cout << "CONTACTOS" << endl;
    listarContactosRest(id, userLoggeado);
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
        quitarParticipante(contacto, id);
        cout << "Participante eliminado con éxito" << endl;
      }else {
        agregarParticipante(contacto, id, userLoggeado);
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

  return cg;
}

ConversacionGrupal* ControllerGrupo::encontrarGrupoPorId(int id)
{
  ControllerConvMens *ccm = ControllerConvMens::getInstancia();
  ConversacionGrupal *cg;
  Conversacion *conver = ccm->getConverSis(id);
  cg = dynamic_cast<ConversacionGrupal *>(conver);
  return cg;
}
