///////////////////////////////////////////////////////////
//  cTrafic.h
//  Implementation of the Class cTrafic
//  Created on:      14-may.-2021 15:26:52
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
#define EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_

#include "cVehiculo.h"

class cTrafic : public cVehiculo
{

public:
	cTrafic();
	virtual ~cTrafic();

	virtual void AnadirAdicionales();
	virtual float CalcularTarifa();
	virtual void PasosMantenimiento();

};
#endif // !defined(EA_3737C318_36CB_4163_A3E3_C785B54048AA__INCLUDED_)
