///////////////////////////////////////////////////////////
//  cCliente.h
//  Implementation of the Class cCliente
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_38B6FEF6_D888_4b51_B635_DC289A931700__INCLUDED_)
#define EA_38B6FEF6_D888_4b51_B635_DC289A931700__INCLUDED_

#include <string>

using namespace std;

class cCliente
{

private:
	string Contacto;
	string Nombre;
	const string DNI;
	unsigned int Edad;

public:
	cCliente();
	virtual ~cCliente();

};
#endif // !defined(EA_38B6FEF6_D888_4b51_B635_DC289A931700__INCLUDED_)
