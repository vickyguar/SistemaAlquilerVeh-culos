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

void cAlquiler::Imprimir() const
{

}

void cAlquiler::setDevuelto()
{
	Devuelto = true;
}

string cAlquiler::To_string() const
{
	string output;

	output += "Fecha de inicio: " +
		to_string(FechaInicio.tm_mday) + '/' +
		to_string(FechaInicio.tm_mon) + '/' +
		to_string(FechaInicio.tm_year) + '\n';
	output += "Fecha de fin: " +
		to_string(FechaFin.tm_mday) + '/' +
		to_string(FechaFin.tm_mon) + '/' +
		to_string(FechaFin.tm_year) + '\n';
	//----------------------------------------------------------------------------------------------------------------------------------------
	switch (Adicional.Adicional1) //solo se switchea la posibilidad de que sea CASCO o SILLA_SEGURIDAD (ver Header.h)
	{
	case eAdicionales::CASCO: output += "Cantidad de cascos alquilados: " + to_string(Adicional.cant1) + '\n'; break;
	case eAdicionales::SILLA_SEGURIDAD: output += "Cantidad de sillas de seguridad alquilados: " + to_string(Adicional.cant1) + '\n'; break;
	}
	//----------------------------------------------------------------------------------------------------------------------------------------
	switch (Adicional.Adicional2)//solo se switchea la posibilidad de que sea ASIENTOS_REBATIBLES o PORTA_EQUIPAJE (ver Header.h)
	{
	case eAdicionales::ASIENTOS_REBATIBLES: output += "Cantidad de asientos rebatibles alquilados: " + to_string(Adicional.cant2) + '\n'; break;
	case eAdicionales::PORTA_EQUIPAJE: output += "Cantidad de porta equipajes alquilados: " + to_string(Adicional.cant2) + '\n'; break;
	}

	output += "Monto total: " + to_string(MontoTotal) + '\n';
	output += "Patente del vehiculo: " + Patente + '\n';
	output += "DNI: " + DNI + '\n';
	output += "Codigo de alquiler: " + Code + '\n';
	output += "Estado de alquiler: ";

	output += Devuelto ? "el vehiculo ya ha sido devuelto" + '\n' : "el vehiculo aun no ha sido devuelto" + '\n';

	return output;

}

string cAlquiler::getClave() const
{
	return Code;
}


