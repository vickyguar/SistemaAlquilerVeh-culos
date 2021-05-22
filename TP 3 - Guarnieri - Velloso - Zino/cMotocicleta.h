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
	cMotocicleta(eEstadoVehiculo estado, float tarifa_base, eColor color, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento,
		const unsigned int capacidad = 2);

	/**
	* ~cMotocicleta
	* destructor de la clase Motocicleta
	*/
	~cMotocicleta();

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
#endif // !defined(EA_5A24C7CC_36CA_4341_A725_018D81902B96__INCLUDED_)
