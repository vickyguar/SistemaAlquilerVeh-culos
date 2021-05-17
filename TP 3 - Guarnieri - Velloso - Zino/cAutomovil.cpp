///////////////////////////////////////////////////////////
//  cAutomovil.cpp
//  Implementation of the Class cAutomovil
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAutomovil.h"


cAutomovil::cAutomovil(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento): 
	cVehiculo::cVehiculo(estado, tarifa_base, adicionales,color, cant_alq, capacidad, chasis, patente,poliza, fecha_ult_mantenimiento)
{
}

cAutomovil::~cAutomovil(){

}

void cAutomovil::AnadirAdicionales(unsigned int cant){


}


float cAutomovil::CalcularTarifa(){

	float result = GetTarifa() + PrecioAlquilerXDia;

	return result;
}


void cAutomovil::PasosMantenimiento(){

}