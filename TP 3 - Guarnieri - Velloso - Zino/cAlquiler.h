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
#include "Headers.h"
using namespace std;

class cAlquiler
{
private:
	sAdicional Adicional;
	tm FechaFin;
	tm FechaInicio;
	float MontoTotal;
	const string DNI;
	const string Patente;
	const string Code;
	bool Devuelto;

public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cAlquiler(sAdicional _Adicional, tm _FechaFin, tm _FechaInicio, float _MontoTotal, const string _DNI, const string _Patente, const string code, bool _Devuelto=false);
	virtual ~cAlquiler();
	
#pragma endregion

	void Imprimir();


#pragma region GETTERS Y SETTERS
	string getClave() const;
	float getMontoTotal()const;
	tm getFechaFin()const;
	sAdicional getAdicionales()const;
	bool getDevuelto();
	void setDevuelto();
#pragma endregion

};
#endif // !defined(EA_6ADA5A65_C03D_413b_A8C7_BF7E575C2E63__INCLUDED_)
