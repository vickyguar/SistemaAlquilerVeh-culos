///////////////////////////////////////////////////////////
//  eColor.h
//  Implementation of the Enumeration eColor
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_C52A1F53_D428_43a1_BDEA_184C2FF46D19__INCLUDED_)
#define EA_C52A1F53_D428_43a1_BDEA_184C2FF46D19__INCLUDED_

#include <ctime>
tm FechaFinAlquiler(unsigned int CantDias, tm FECHA);

enum class eColor
{
	GRIS = 1,
	NEGRO,
	BLANCO,
	ROJO,
	AZUL
};

enum class eEstadoVehiculo
{
	ALQUILADO = 1,
	EN_MANTENIMIENTO,
	DISPONIBLE,
	FUERA_CIRCULACION
};

enum class eAdicionales
{
	CASCO = 100,
	SILLA_SEGURIDAD = 200,
	PORTA_EQUIPAJE = 300,
	ASIENTOS_REBATIBLES = 400,
	NINGUNO = 0
};

struct sAdicional {
							 //    CAMIONETA            |           TRAFIC             |       MOTO     |     AUTO
	eAdicionales Adicional1; //SILLA DE SEGURIDAD       |      SILLA DE SEGURIDAD      |      CASCO     |    SILLAS DE SEGURIDAD
	eAdicionales Adicional2; //PORTAEQUIPAJE            |      ASIENTO RETRAIBLE       |    NINGUNO     |    NINGUNO
	unsigned int cant1;
	unsigned int cant2;
};
#endif // !defined(EA_C52A1F53_D428_43a1_BDEA_184C2FF46D19__INCLUDED_)
