#include "DtFechaHora.h"

DtFechaHora::DtFechaHora(){};

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int min){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
    this->hora=hora;
    this->min=min;
}

//Gettes
int DtFechaHora::getDia(){
    return this->dia=dia;
}

int DtFechaHora::getMes(){
    return this->mes=mes;
}

int DtFechaHora::getAnio(){
    return this->anio=anio;
}

int DtFechaHora::getHora(){
    return this->hora=hora;
}

int DtFechaHora::getMin(){
    return this->min=min;
}

void DtFechaHora::mostrarFechayHora(){
    cout << endl;
    cout <<"Fecha: "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout << endl;
    cout <<"Hora: "<<getHora()<<":"<<getMin();
}

void DtFechaHora::mostrarFechayHoraConexion(){
    cout << endl;
    cout <<"Fecha de última conexión: "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout << endl;
    cout <<"Hora de última conexión: "<<getHora()<<":"<<getMin();
    cout << endl;
}

void DtFechaHora::mostrarFechayHoraRegistro(){
    cout << endl;
    cout <<"Fecha de registro: "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout << endl;
    cout <<"Hora de registro: "<<getHora()<<":"<<getMin();
    cout << endl;
}

void DtFechaHora::mostrarFechayHoraVisto(){
    cout << endl;
    cout <<"VISTO el "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout <<" a las "<<getHora()<<":"<<getMin();
}

void DtFechaHora::mostrarFechayHoraEnviado(){
    cout << endl;
    cout <<"ENVIADO el "<<this->getDia()<<"/"<<this->getMes()<<"/"<<getAnio();
    cout <<" a las "<<getHora()<<":"<<getMin();
}

 DtFechaHora::~DtFechaHora() {};
