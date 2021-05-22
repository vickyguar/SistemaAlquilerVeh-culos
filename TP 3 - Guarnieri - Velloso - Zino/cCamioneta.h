///////////////////////////////////////////////////////////
//  cCaminoeta.h
//  Implementation of the Class cCaminoeta
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_)
#define EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_

#include "cVehiculo.h"

class cCamioneta : public cVehiculo
{
private:
	static float PrecioAlquilerXDia;
public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cCamioneta
	* constructor de automovil
	* @param estado del vehiculo, tarifa base, adicionales, color
	* cantidad de alquileres, capacidad de pasajeros, chasis, patente, poliza, fecha de ultimo mantenimiento
	*/
	cCamioneta(eEstadoVehiculo estado, float tarifa_base, sAdicional adicionales, eColor color, const string chasis, const string patente, const string poliza, tm fecha_ult_mantenimiento, const unsigned int capacidad = 7);

	/**
	* ~cCamioneta
	* destructor de la clase Camioneta
	*/
	~cCamioneta();

#pragma endregion
	
	/**
* AñadirAdicionales
* permite que se añadan adicionales al alquiler. El precio de estos se agrega a precio por dia
*/
	void AnadirAdicionales(unsigned int cant_portaequipaje, unsigned int cant_sillas);
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
#endif // !defined(EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_)
