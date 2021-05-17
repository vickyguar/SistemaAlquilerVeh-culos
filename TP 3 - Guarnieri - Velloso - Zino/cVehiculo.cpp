///////////////////////////////////////////////////////////
//  cVehiculo.cpp
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cVehiculo.h"

float cVehiculo::PrecioAlquilerXDia = 1000;

cVehiculo::cVehiculo(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento): 
	CapacidadPasajeros(capacidad), Chasis(chasis), Patente(patente), Poliza(poliza)
{
	this->Estado = estado;
	this->TarifaBase = tarifa_base;
	this->Adicionales = adicionales;
	this->Color = color;
	this->CantAdicionalesAlquilados = cant_alq;
	this->UltimoMantenimiento = fecha_ult_mantenimiento;
}

cVehiculo::~cVehiculo(){

}

void cVehiculo::AnadirAdicionales(unsigned int cant){
	this->CantAdicionalesAlquilados = cant;
}

float cVehiculo::CalcularTarifa(){
	float aux = TarifaBase + PrecioAlquilerXDia;
	return;
}

string cVehiculo::PasosMantenimiento(){

}

float cVehiculo::GetTarifa()
{
	return TarifaBase;
}


string cVehiculo::getPatente() const
{
	return Patente;
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
