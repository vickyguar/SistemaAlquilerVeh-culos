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

struct sAdicional {
	eAdicionales Adicional1;
	eAdicionales Adicional2;
	unsigned int cant1;
	unsigned int cant2;
};

class cVehiculo
{

private:
	 
	static float TarifaBase;

protected:
	eEstadoVehiculo Estado;//No es const por si queremos cambiarla
	sAdicional Adicionales; //tiene el precio igualado en el enum para poder hacer ++
	eColor Color; 
	const unsigned int CapacidadPasajeros;
	const string Chasis;
	const string Patente;
	const string Poliza;
	tm UltimoMantenimiento;

public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cVehiculo
	* constructor de automovil
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cVehiculo(eEstadoVehiculo estado, float tarifa_base, eAdicionales adicionales, eColor color,
		const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento);

	/**
	* ~cVehiculo
	* destructor de la clase cAutomovil
	*/
	virtual ~cVehiculo();
#pragma endregion

	virtual void AnadirAdicionales(unsigned int cant);
	virtual float CalcularTarifas();
	virtual string PasosMantenimiento();

#pragma region GETTERS & SETTERS
	string getClave()const;
	float getTarifaBase()const; //se puede poner en el virtual?
	eEstadoVehiculo getEstado()const;
	void setEstado(eEstadoVehiculo newEstado);
	void setFechaUltMantenimiento(tm newUltMantenimiento);
	void setTarifaBase(float tarifa);
	virtual float getPrecioXDia()const;
#pragma endregion
	virtual string To_string() const;

};
#endif // !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
