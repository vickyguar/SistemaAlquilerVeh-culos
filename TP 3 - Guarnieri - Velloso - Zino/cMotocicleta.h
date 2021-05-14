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

public:
	cMotocicleta();
	virtual ~cMotocicleta();

	virtual void AnadirAdicionales();
	virtual float CalcularTarifa();
	virtual void PasosMantenimiento();

};
#endif // !defined(EA_5A24C7CC_36CA_4341_A725_018D81902B96__INCLUDED_)
