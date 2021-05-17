///////////////////////////////////////////////////////////
//  cAlquiler.h
//  Implementation of the Class cAlquiler
//  Created on:      14-may.-2021 15:26:50
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_6ADA5A65_C03D_413b_A8C7_BF7E575C2E63__INCLUDED_)
#define EA_6ADA5A65_C03D_413b_A8C7_BF7E575C2E63__INCLUDED_

#include <ctime>
#include <string>
using namespace std;

class cAlquiler
{
private:
	unsigned int CantAdicionales;
	tm FechaFin;
	tm FechaInicio;
	float MontoTotal;
	const string DNI;
	const string Patente;

public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cAlquiler(unsigned int _CantidadAdicionales, tm _FechaFin, tm _FechaInicio, float _MontoTotal, const string _DNI, const string _Patente);
	virtual ~cAlquiler();
	float getMontoTotal();
	void Imprimir();
#pragma endregion

};
#endif // !defined(EA_6ADA5A65_C03D_413b_A8C7_BF7E575C2E63__INCLUDED_)
