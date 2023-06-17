#include "DtFechaHora.h"

DtFechaHora::DtFechaHora(){};

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int min){
    this-> dia=dia;
    this-> mes=mes;
    this-> anio=anio;
    this-> hora=hora;
    this-> min=min;
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

 DtFechaHora::~DtFechaHora() {};
