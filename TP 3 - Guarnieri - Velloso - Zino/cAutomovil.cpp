///////////////////////////////////////////////////////////
//  cAutomovil.cpp
//  Implementation of the Class cAutomovil
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAutomovil.h"

float cAutomovil::PrecioAlquilerXDia = 20000;
cAutomovil::cAutomovil(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, const unsigned int capacidad = 4, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento):
	cVehiculo::cVehiculo(estado, tarifa_base, adicionales,color, capacidad, chasis, patente,poliza, fecha_ult_mantenimiento)
{
}

cAutomovil::~cAutomovil(){

}

void cAutomovil::AnadirAdicionales(unsigned int cant){

	if (cant >= 1 || cant <= 3) //si quiere añadir 1 o más (hasta 3) sillas de seguridad 
		PrecioAlquilerXDia += cant * ((int)eAdicionales::SILLA_SEGURIDAD); //se suma el costo a el precio por día
	return;
}


float cAutomovil::CalcularTarifa(unsigned int dias){
	float aux = PrecioAlquilerXDia * dias + getTarifaBase();

	return aux;
}


string cAutomovil::PasosMantenimiento(){

	string steps = "PASOS MANTENIMIENTO AUTOMOVIL: \n";
	steps += "1. Cambio de filtros y de aceite \n";
	steps += "2. Revision de frenos\n";
	steps += "3. Neumáticos\n";
	steps += "4. Amortiguadores\n";
	steps += "5. Revisión de las luces\n";

	return steps;
}
