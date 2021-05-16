///////////////////////////////////////////////////////////
//  cVehiculo.h
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
#define EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_

#include <string>
#include "eColor.h"
#include "eEstadoVehiculo.h"
#include "eAdicionales.h"
#include <time.h>

using namespace std;

class cVehiculo
{

public:
	cVehiculo();
	virtual ~cVehiculo();

	virtual void AnadirAdicionales();
	virtual float CalcularTarifa();
	virtual void PasosMantenimiento();

protected:
	/**
	 * tiene el precio igualado en el enum para poder hacer ++
	 */
	eAdicionales Adicionales;
	unsigned int CantAdicionalesAlquilados;
	const unsigned int CapacidadPasajeros;
	const string Chasis;
	eColor Color;
	const string Patente;
	const string Poliza;
	static float PrecioAlquilerXDia;
	tm UltimoMantenimiento;

private:
	eEstadoVehiculo Estado;
	/**
	 * No es const por si queremos cambiarla
	 */
	float TarifaBase;

};
#endif // !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
