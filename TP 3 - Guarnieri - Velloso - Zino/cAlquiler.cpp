///////////////////////////////////////////////////////////
//  cAlquiler.cpp
//  Implementation of the Class cAlquiler
//  Created on:      14-may.-2021 15:26:50
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAlquiler.h"

//LA PALABRA CONST NO VA
cAlquiler::cAlquiler(unsigned int _CantAdicionales, tm _FechaFin, tm _FechaInicio, float _MontoTotal, const string _DNI, const string _Patente, const string code,bool _Devuelto)
	:DNI(_DNI), Patente(_Patente), Code(code)
{
	CantAdicionales = _CantAdicionales;
	FechaFin = _FechaFin;
	FechaInicio = _FechaInicio;
	MontoTotal = _MontoTotal;
	Devuelto = _Devuelto;
}

cAlquiler::~cAlquiler(){

}

float cAlquiler::getMontoTotal()
{
	return MontoTotal;
}

tm cAlquiler::getFechaFin()
{
	return FechaFin;
}

unsigned int cAlquiler::getAdicionales()
{
	return CantAdicionales;
}

void cAlquiler::Imprimir()
{
}

void cAlquiler::setDevuelto()
{
	Devuelto = true;
}

string cAlquiler::getClave() const
{
	return Code;
}

