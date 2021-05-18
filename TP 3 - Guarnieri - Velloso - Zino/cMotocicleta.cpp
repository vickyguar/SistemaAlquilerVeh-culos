///////////////////////////////////////////////////////////
//  cMotocicleta.cpp
//  Implementation of the Class cMotocicleta
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cMotocicleta.h"

float cMotocicleta::PrecioAlquilerXDia = 500;
cMotocicleta::cMotocicleta(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq, const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento):
		cVehiculo::cVehiculo(estado, tarifa_base, adicionales, color, capacidad, chasis, patente, poliza, fecha_ult_mantenimiento)
{
}

cMotocicleta::~cMotocicleta(){

}

void cMotocicleta::AnadirAdicionales(unsigned int cant){

	if (cant == 1 || cant == 2) //si quieren añadir 1 o 2 cascos
		PrecioAlquilerXDia += cant * ((int)eAdicionales::CASCO);
	return;
}

float cMotocicleta::CalcularTarifa(unsigned int dias){

	float result = getTarifaBase() + PrecioAlquilerXDia*dias;

	return result;
}


string cMotocicleta::PasosMantenimiento(){
	string steps = "PASOS MANTENIMIENTO MOTOCICLETA: \n";
	steps += "1. Comprobar el nivel de aceite del carter \n";
	steps += "2. Comprobar las ruedas\n";
	steps += "3. Comprobar la batería\n";
	steps += "4. Comprobar las pastillas de freno y la cadena\n";
	steps += "5. Limpiar y lubricar\n";

	return steps;
}