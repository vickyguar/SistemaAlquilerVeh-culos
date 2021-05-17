///////////////////////////////////////////////////////////
//  cCaminoeta.cpp
//  Implementation of the Class cCaminoeta
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cCamioneta.h"


cCamioneta::cCamioneta(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento):
	cVehiculo::cVehiculo(estado, tarifa_base, adicionales, color, cant_alq, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cCamioneta::~cCamioneta(){

}

void cCamioneta::AnadirAdicionales(unsigned int cant_portaequipaje, unsigned int cant_sillas) {
	if (cant_portaequipaje == 1) //si quiere añadir un portaequipaje
		PrecioAlquilerXDia += cant_portaequipaje * ((int)eAdicionales::PORTA_EQUIPAJE); //se suma el costo a el precio por día

	if (cant_sillas >= 1 || cant_sillas <= 3) //si quiere añadir 1 o más (hasta 3) sillas de seguridad 
		PrecioAlquilerXDia += cant_sillas * ((int)eAdicionales::SILLA_SEGURIDAD); //se suma el costo a el precio por día
	return;
}


float cCamioneta::CalcularTarifa(){

	float result = GetTarifa() + PrecioAlquilerXDia;

	return result;
}


void cCamioneta::PasosMantenimiento(){

}