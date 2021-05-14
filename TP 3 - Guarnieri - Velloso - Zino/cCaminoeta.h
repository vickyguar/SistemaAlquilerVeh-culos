///////////////////////////////////////////////////////////
//  cCaminoeta.h
//  Implementation of the Class cCaminoeta
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_)
#define EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_

#include "cVehiculo.h"

class cCaminoeta : public cVehiculo
{

public:
	cCaminoeta();
	virtual ~cCaminoeta();

	void AnadirAdicionales();
	float CalcularTarifa();
	void PasosMantenimiento();

};
#endif // !defined(EA_47399F2C_B863_4471_87EE_0238E7D8DCB0__INCLUDED_)
