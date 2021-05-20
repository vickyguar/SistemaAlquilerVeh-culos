///////////////////////////////////////////////////////////
//  cMotocicleta.h
//  Implementation of the Class cMotocicleta
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_5A24C7CC_36CA_4341_A725_018D81902B96__INCLUDED_)
#define EA_5A24C7CC_36CA_4341_A725_018D81902B96__INCLUDED_

#include "cVehiculo.h"

class cMotocicleta : public cVehiculo
{
private:
	static float PrecioAlquilerXDia;
public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cMotocicleta
	* constructor de motocicleta
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cMotocicleta(eEstadoVehiculo estado, float tarifa_base, sAdicional adicional, eColor color, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento,
		const unsigned int capacidad = 2);

	/**
	* ~cMotocicleta
	* destructor de la clase Motocicleta
	*/
	virtual ~cMotocicleta();

#pragma endregion

	virtual void AnadirAdicionales(unsigned int cant);
	virtual float CalcularTarifa(unsigned int dias);
	virtual string PasosMantenimiento();
	virtual float getPrecioXDia()const;

	virtual string To_string()const;

};
#endif // !defined(EA_5A24C7CC_36CA_4341_A725_018D81902B96__INCLUDED_)
