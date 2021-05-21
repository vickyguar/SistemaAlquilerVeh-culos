///////////////////////////////////////////////////////////
//  cVehiculo.h
//  Implementation of the Class cVehiculo
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
#define EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_

#include <string>
#include "Headers.h"
#include <ctime>
#include <iostream>

using namespace std;

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
	cVehiculo(eEstadoVehiculo estado, float tarifa_base, sAdicional adicionales, eColor color, const unsigned int capacidad, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento);

	/**
	* ~cVehiculo
	* destructor de la clase cAutomovil
	*/
	virtual ~cVehiculo();
#pragma endregion

	/**
* AñadirAdicionales
* permite que se añadan adicionales al alquiler. El precio de estos se agrega a precio por dia
*/
	virtual void AnadirAdicionales(sAdicional adicional);
	/**
	* CalcularTarifas
	* calcula la tarifa a abonar por el cliente
	*/
	virtual float CalcularTarifa(unsigned int dias);
	/**
* PasosMantenimiento
* crea un string con los pasos de mantenimiento de un auto
*/
	virtual string PasosMantenimiento();

#pragma region GETTERS & SETTERS

	string getClave()const;
	float getTarifaBase()const; 
	eEstadoVehiculo getEstado()const;
	void setEstado(eEstadoVehiculo newEstado);
	void setFechaUltMantenimiento(tm newUltMantenimiento);
	void setTarifaBase(float tarifa);
	virtual float getPrecioXDia()const;

#pragma endregion

#pragma region IMPRIMIR & TO STRING

	/**
* To_string
* crea un string con todos los atributos de la calse
*/
	virtual string To_string() const;
	/**
		* Imprimir
		* imprime los atributos en pantalla.
		*/
	virtual void Imprimir();

#pragma endregion

};
#endif // !defined(EA_EC55E7BC_2390_417c_A6F2_559933EB7B4E__INCLUDED_)
