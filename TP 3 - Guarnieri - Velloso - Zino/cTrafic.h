///////////////////////////////////////////////////////////
//  cTrafic.h
//  Implementation of the Class cTrafic
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
#define EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_

#include "cVehiculo.h"

class cTrafic : public cVehiculo
{
private:
	static float PrecioAlquilerXDia;
public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cTrafic
	* constructor de trafic
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cTrafic(eEstadoVehiculo estado, float tarifa_base, sAdicional adicionales, eColor color,
		const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento, const unsigned int capacidad = 10);

	/**
	* ~cTrafic
	* destructor de la clase Trafic
	*/
	virtual ~cTrafic();

#pragma endregion

	virtual void AnadirAdicionales(unsigned int cant_portaequipaje, unsigned int cant_sillas);
	virtual float CalcularTarifa(unsigned int dias);
	virtual string PasosMantenimiento();
	virtual float getPrecioXDia()const;

};
#endif // !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
