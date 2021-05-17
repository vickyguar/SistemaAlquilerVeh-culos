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

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cTrafic
	* constructor de trafic
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cTrafic(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq,
		unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento);

	/**
	* ~cTrafic
	* destructor de la clase Trafic
	*/
	virtual ~cTrafic();

#pragma endregion

	virtual void AnadirAdicionales();
	virtual float CalcularTarifa();
	virtual void PasosMantenimiento();

};
#endif // !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
