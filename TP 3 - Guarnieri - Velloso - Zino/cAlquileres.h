///////////////////////////////////////////////////////////
//  cAlquileres.h
//  Implementation of the Class cAlquileres
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_28424133_7ED8_4704_BCB7_1D640A9AC898__INCLUDED_)
#define EA_28424133_7ED8_4704_BCB7_1D640A9AC898__INCLUDED_

#include "cVehiculo.h"
#include "cAlquiler.h"

class cAlquileres
{

public:
	cAlquileres();
	virtual ~cAlquileres();
	cAlquiler *m_cAlquiler;

	void CalcularGananciaTotal();
	void ListarXVehiculo(cVehiculo Vehiculo);

};
#endif // !defined(EA_28424133_7ED8_4704_BCB7_1D640A9AC898__INCLUDED_)
