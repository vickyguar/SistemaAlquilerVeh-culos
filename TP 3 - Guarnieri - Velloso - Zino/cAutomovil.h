///////////////////////////////////////////////////////////
//  cAutomovil.h
//  Implementation of the Class cAutomovil
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_)
#define EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_

#include "cVehiculo.h"

class cAutomovil : public cVehiculo
{
private:
	static float PrecioAlquilerXDia;
public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cAutomovil 
	* constructor de automovil
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cAutomovil(eEstadoVehiculo estado, float tarifa_base, eColor color, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento, const unsigned int capacidad);

	/**
	* ~cAutomovil 
	* destructor de la clase cAutomovil
	*/
	~cAutomovil();

#pragma endregion

	/**
	* AñadirAdicionales 
	* permite que se añadan adicionales al alquiler. El precio de estos se agrega a precio por dia
	*/
	void AnadirAdicionales(unsigned int cant);
	/**
	* CalcularTarifas 
	* calcula la tarifa a abonar por el cliente
	*/
	float CalcularTarifa(unsigned int dias);

	/**
* PasosMantenimiento
* crea un string con los pasos de mantenimiento de un auto
*/
	string PasosMantenimiento();
	/**
* To_string
* crea un string con todos los atributos de la calse
*/
	string To_string() const;
	/**
	* Imprimir
	* imprime los atributos en pantalla
	*/
	void Imprimir() const;

	float getPrecioXDia()const; //getter
};
#endif // !defined(EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_)
