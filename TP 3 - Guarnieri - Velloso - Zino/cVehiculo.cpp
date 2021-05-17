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

void cVehiculo::AnadirAdicionales(){

}

float cVehiculo::CalcularTarifa(){

	return;
}

void cVehiculo::PasosMantenimiento(){

}

float cVehiculo::GetTarifa()
{
	return TarifaBase;
}
