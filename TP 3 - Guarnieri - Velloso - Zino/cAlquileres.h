///////////////////////////////////////////////////////////
//  cAlquileres.h
//  Implementation of the Class cAlquileres
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_28424133_7ED8_4704_BCB7_1D640A9AC898__INCLUDED_)
#define EA_28424133_7ED8_4704_BCB7_1D640A9AC898__INCLUDED_

#include "cAlquiler.h"
#include "cListaTemplate.h"
#include "cAutomovil.h"
#include "cCamioneta.h"
#include "cMotocicleta.h"
#include "cTrafic.h"

class cAlquileres:public cListaTemplate<class cAlquiler>
{

public:
	/**
* cAlquileres 
* constructor de clase cAlquileres
* @param TAM, delete
*/
	cAlquileres(unsigned int _TAM = NMAX, bool _Delete = true);
	/**
* ~cAlquileres
* destructor de la clase cAutomovil
*/
	~cAlquileres();
	/**
	* CalcularGanancia
	* calcula la ganancia de la empresa, sumando los montostotales
	*/
	float CalcularGanancia();
	float ListarXCamioneta();
	float ListarXTrafic();
	/**
	* ListarXVehiculo
	*  lista por tipo de vehiculo
	*  devuelve la ganancia total de los alquileres de este tipo de vehiculo
	* @param vehiculo
	*/
	float ListarXAutomovil();
	float ListarXMotocicleta();
	float ListarXVehiculo();


};
#endif // !defined(EA_28424133_7ED8_4704_BCB7_1D640A9AC898__INCLUDED_)
