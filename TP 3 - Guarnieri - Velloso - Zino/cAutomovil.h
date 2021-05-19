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
	cAutomovil(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color,
		const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento);

	/**
	* ~cAutomovil 
	* destructor de la clase cAutomovil
	*/
	virtual ~cAutomovil();

#pragma endregion

	

	virtual void AnadirAdicionales(unsigned int cant);
	virtual float CalcularTarifa(unsigned int dias);
	virtual string PasosMantenimiento();
	virtual string To_string() const;

};
#endif // !defined(EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_)
