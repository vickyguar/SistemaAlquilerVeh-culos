///////////////////////////////////////////////////////////
//  cVehiculo.cpp
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cVehiculo.h"


cVehiculo::cVehiculo(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento):
	CapacidadPasajeros(capacidad), Chasis(chasis), Patente(patente), Poliza(poliza)
{
	this->Estado = estado;
	this->TarifaBase = tarifa_base;
	this->Adicionales = adicionales;
	this->Color = color;
	this->CantAdicionalesAlquilados = 0;
	this->UltimoMantenimiento = fecha_ult_mantenimiento;
}

cVehiculo::~cVehiculo(){

}

void cVehiculo::AnadirAdicionales(unsigned int cant){
	this->CantAdicionalesAlquilados = cant;
}

float cVehiculo::CalcularTarifas(){
	

}

string cVehiculo::PasosMantenimiento(){

}


string cVehiculo::getPatente() const
{
	return Patente;
}

float cVehiculo::getTarifaBase()
{
	return TarifaBase;
}

eEstadoVehiculo cVehiculo::getEstado() const
{
	return Estado;
}

void cVehiculo::setEstado(eEstadoVehiculo newEstado)
{
	Estado = newEstado;
}

void cVehiculo::setFechaUltMantenimiento(tm newUltMantenimiento)
{
	UltimoMantenimiento = newUltMantenimiento;
}
