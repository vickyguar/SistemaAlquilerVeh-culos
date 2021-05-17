///////////////////////////////////////////////////////////
//  cTrafic.cpp
//  Implementation of the Class cTrafic
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTrafic.h"


cTrafic::cTrafic(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento):
	cVehiculo::cVehiculo(estado, tarifa_base, adicionales, color, cant_alq, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cTrafic::~cTrafic(){

}

void cTrafic::AnadirAdicionales(unsigned int cant){

}


float cTrafic::CalcularTarifa(){

	float result = GetTarifa() + PrecioAlquilerXDia;

	return result;
}


void cTrafic::PasosMantenimiento(){

}