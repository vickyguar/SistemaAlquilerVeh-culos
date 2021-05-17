///////////////////////////////////////////////////////////
//  cMotocicleta.cpp
//  Implementation of the Class cMotocicleta
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cMotocicleta.h"


cMotocicleta::cMotocicleta(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento):
		cVehiculo::cVehiculo(estado, tarifa_base, adicionales, color, cant_alq, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cMotocicleta::~cMotocicleta(){

}

void cMotocicleta::AnadirAdicionales(){

}


float cMotocicleta::CalcularTarifa(){

	float result = GetTarifa() + PrecioAlquilerXDia;

	return result;
}


void cMotocicleta::PasosMantenimiento(){

}