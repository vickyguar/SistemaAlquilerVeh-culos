///////////////////////////////////////////////////////////
//  cAutomovil.h
//  Implementation of the Class cAutomovil
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_)
#define EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_

#include "cVehiculo.h"

class cAutomovil : public cVehiculo
{

public:
	cAutomovil();
	virtual ~cAutomovil();

	virtual void AnadirAdicionales();
	virtual float CalcularTarifa();
	virtual void PasosMantenimiento();

};
#endif // !defined(EA_13DEC193_FD8B_4c41_B1BB_56B69270B260__INCLUDED_)
