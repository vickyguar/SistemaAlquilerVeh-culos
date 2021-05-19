///////////////////////////////////////////////////////////
//  cVehiculo.cpp
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cVehiculo.h"

float cVehiculo::TarifaBase= 10000;
cVehiculo::cVehiculo(eEstadoVehiculo estado, float tarifa_base, sAdicional adicionales, eColor color, const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento):
	CapacidadPasajeros(capacidad), Chasis(chasis), Patente(patente), Poliza(poliza)
{
	this->Estado = estado;
	this->TarifaBase = tarifa_base;
	this->Adicionales = adicionales;
	this->Color = color;
	this->UltimoMantenimiento = fecha_ult_mantenimiento;
}

cVehiculo::~cVehiculo(){
}

void cVehiculo::AnadirAdicionales(sAdicional adicional){
	this->Adicionales = adicional;
}

float cVehiculo::CalcularTarifas(){
	return float(); //TODO: calcular tarifas
}

string cVehiculo::PasosMantenimiento(){
	return string();
}


string cVehiculo::getClave() const
{
	return Patente;
}

float cVehiculo::getTarifaBase() const
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

string cVehiculo::To_string()const
{
	string output;
	//----------------------------------------------------------------------------------------------------
	switch (Estado) {
	case eEstadoVehiculo::ALQUILADO: output += "Estado de vehiculo: Alquilado " + '\n'; break;
	case eEstadoVehiculo::DISPONIBLE: output += "Estado de vehiculo: Disponible " + '\n'; break;
	case eEstadoVehiculo::EN_MANTENIMIENTO: output += "Estado de vehiculo: En mantenimiento " + '\n'; break;
	case eEstadoVehiculo::FUERA_CIRCULACION: output += "Estado de vehiculo: Fuera de circulacion " + '\n'; break;
	}
	//----------------------------------------------------------------------------------------------------
	switch (Color) {
	case eColor::AZUL: output += "Color: azul" + '\n';
	case eColor::BLANCO:output += "Color: blanco" + '\n';
	case eColor::GRIS:output += "Color: gris" + '\n';
	case eColor::NEGRO:output += "Color: negro" + '\n';
	case eColor::ROJO:output += "Color: rojo" + '\n';
	}
	//----------------------------------------------------------------------------------------------------
	output += "Capacidad de pasajeros: " + CapacidadPasajeros + '\n';
	output += "Numero de chasis: " + Chasis + '\n';
	output += "Ptente: " + Patente + '\n';
	output += "Poliza: " + Poliza + '\n';
	output += "Fecha del ultimo mantenimiento: " +
		to_string(UltimoMantenimiento.tm_mday) + '/' +
		to_string(UltimoMantenimiento.tm_mon) + '/' +
		to_string(UltimoMantenimiento.tm_year) + '\n';

	return output;

}
void cVehiculo::setTarifaBase(float tarifa)
{
	TarifaBase = tarifa;
}

float cVehiculo::getPrecioXDia() const
{
	return float();
}
