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

void ControllerGrupo::listarContactosPart(ConversacionGrupal* grupo)
{
  map<int, Usuario*> colParticipantes = grupo->getListaParticipantes();
  for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
  {
    cout << it->second->getNombre() << " -: " << it->second->getNumTel() << endl;
  }


}

void ControllerGrupo::listarContactosRest(ConversacionGrupal* grupo)
{
  ControllerSesion* cs = ControllerSesion::getInstancia();
  Usuario* user = cs->getUserLoggeado();
  map<int, Usuario*> colRestantes = user->getListaContactos();
  map<int, Usuario*> colParticipantes = grupo->getListaParticipantes();
  for (auto it = colRestantes.begin(); it != colRestantes.end(); it++)
  {
    if (colParticipantes.find(it->first) == colParticipantes.end())
    {
      cout << "\n----------------------------\n";
      cout << it->second->getNombre() << " -: " << it->second->getNumTel() << endl;
    }
    
  }

}

void ControllerGrupo::agregarParticipante(int numTel, int id)
{
  ControllerSesion* cs = ControllerSesion::getInstancia();
  Usuario* user = cs->getUserLoggeado();
  Usuario* participante = user->getContacto(numTel);
  ConversacionGrupal* cg = encontrarGrupoPorId(id);
  cg->setParticipante(participante);
}

void ControllerGrupo::agregarAdministrador(int numTel, int id)
{
  ControllerSesion* cs = ControllerSesion::getInstancia();
  Usuario* user = cs->getUserLoggeado();
  Usuario* administrador = user->getContacto(numTel);
  ConversacionGrupal* cg = encontrarGrupoPorId(id);
  cg->setAdministrador(administrador);
}

void ControllerGrupo::quitarParticipante(int numTel, int id)
{
  ControllerSesion* cs = ControllerSesion::getInstancia();
  Usuario* participante = cs->getUserLoggeado();
}

ConversacionGrupal* ControllerGrupo::crearGrupo(string nombre, string url, DtFechaHora* fechayHora)
{
  int id = rand()%100+1;
  ControllerSesion* cs = ControllerSesion::getInstancia();
  Usuario* user = cs->getUserLoggeado();
  ConversacionGrupal* cg = new ConversacionGrupal(id, true, nombre, url, fechayHora);
  Conversacion* conver = cg;
  cg = dynamic_cast<ConversacionGrupal*>(conver);
  cg->setAdministrador(user);
  user->setConver(cg);
  cout << "Grupo creado con el id: " << id <<endl;
}

ConversacionGrupal* ControllerGrupo::encontrarGrupoPorId(int id)
{
  this->getInstancia();
  Usuario* user = NULL;
  ControllerConvMens* ccm = ControllerConvMens::getInstancia();
  ConversacionGrupal* cg = new ConversacionGrupal();
  Conversacion* conver = ccm->getConverSis(id);
  cg = dynamic_cast<ConversacionGrupal*>(conver);
  return cg;
}
