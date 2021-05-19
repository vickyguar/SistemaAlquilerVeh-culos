///////////////////////////////////////////////////////////
//  cAlquiler.cpp
//  Implementation of the Class cAlquiler
//  Created on:      14-may.-2021 15:26:50
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAlquiler.h"

//LA PALABRA CONST NO VA
cAlquiler::cAlquiler(sAdicional _Adicional, tm _FechaFin, tm _FechaInicio, float _MontoTotal, const string _DNI, const string _Patente, const string code, bool _Devuelto)
	:DNI(_DNI), Patente(_Patente), Code(code)
{
	Adicional = _Adicional;
	FechaFin = _FechaFin;
	FechaInicio = _FechaInicio;
	MontoTotal = _MontoTotal;
	Devuelto = _Devuelto;
}

cAlquiler::~cAlquiler(){

}

float cAlquiler::getMontoTotal() const
{
	return MontoTotal;
}

tm cAlquiler::getFechaFin() const
{
	return FechaFin;
}

sAdicional cAlquiler::getAdicionales() const
{
	return Adicional;
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

