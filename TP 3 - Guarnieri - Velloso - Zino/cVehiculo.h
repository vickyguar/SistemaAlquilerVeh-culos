///////////////////////////////////////////////////////////
//  cVehiculo.h
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
#define EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_

#include <string>
#include "enums.h"
#include <ctime>

using namespace std;

class cVehiculo
{

private:
	eEstadoVehiculo Estado; //No es const por si queremos cambiarla
	float TarifaBase;

protected:
	eAdicionales Adicionales; //tiene el precio igualado en el enum para poder hacer ++
	eColor Color;
	unsigned int CantAdicionalesAlquilados;
	const unsigned int CapacidadPasajeros;
	const string Chasis;
	const string Patente;
	const string Poliza;
	static float PrecioAlquilerXDia;
	tm UltimoMantenimiento;

public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cVehiculo
	* constructor de automovil
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cVehiculo(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color, unsigned int cant_alq,
		unsigned int capacidad, string chasis, string patente, string poliza, tm fecha_ult_mantenimiento);

	/**
	* ~cVehiculo
	* destructor de la clase cAutomovil
	*/
	virtual ~cVehiculo();
#pragma endregion

	virtual void AnadirAdicionales(unsigned int cant);
	virtual float CalcularTarifa();
	virtual void PasosMantenimiento();
	float GetTarifa();

#pragma region GETTERS & SETTERS
	string getPatente()const;
	eEstadoVehiculo getEstado()const;
	void setEstado(eEstadoVehiculo newEstado);
	void setFechaUltMantenimiento(tm newUltMantenimiento);
#pragma endregion


};
#endif // !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
