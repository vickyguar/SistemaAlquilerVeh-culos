///////////////////////////////////////////////////////////
//  cTrafic.cpp
//  Implementation of the Class cTrafic
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTrafic.h"

float cTrafic::PrecioAlquilerXDia=1800.0;
cTrafic::cTrafic(eEstadoVehiculo estado, float tarifa_base, sAdicional adicionales, eColor color, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento, const unsigned int capacidad):
	cVehiculo::cVehiculo(estado, tarifa_base, adicionales, color, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cTrafic::~cTrafic(){

}

void cTrafic::AnadirAdicionales(unsigned int cant_asientos, unsigned int cant_sillas){
	if (cant_asientos >= 1|| cant_asientos <= 10) //si quiere añadir asientos retraibles
		PrecioAlquilerXDia += cant_asientos * ((int)eAdicionales::ASIENTOS_REBATIBLES); //se suma el costo a el precio por día

	if (cant_sillas >= 1 || cant_sillas <= 5) //si quiere añadir 1 o más (hasta 5) sillas de seguridad 
		PrecioAlquilerXDia += cant_sillas * ((int)eAdicionales::SILLA_SEGURIDAD); //se suma el costo a el precio por día
	return;
}


float cTrafic::CalcularTarifa(unsigned int dia){

	float result = getTarifaBase() + PrecioAlquilerXDia*dia;

	return result;
}


string cTrafic::PasosMantenimiento(){
	string steps = "PASOS MANTENIMIENTO TRAFIC: \n";
	steps += "1. Revisión de fluidos \n";
	steps += "2. Estado de batería\n";
	steps += "3. Revision de frenos\n";
	steps += "4. Neumáticos\n";
	steps += "5. Amortiguadores\n";
	steps += "6. Revisión de las luces\n";
	return steps;
}

float cTrafic::getPrecioXDia() const
{
	return PrecioAlquilerXDia;
}