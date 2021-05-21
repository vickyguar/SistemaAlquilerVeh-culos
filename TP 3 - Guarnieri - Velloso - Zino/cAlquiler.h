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
#include <iostream>
#include "Headers.h"
#include "cVehiculo.h"
using namespace std;

class cAlquiler
{
private:
	sAdicional Adicional;
	tm FechaFin;
	tm FechaInicio;
	float MontoTotal;
	const string DNI;
	cVehiculo* Vehiculo;
	const string Code; //Por si tenemos que buscar en la lista de alquileres 
	bool Devuelto;

public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	/**
* cAlquiler
* constructor de alquiler
* @param adicionales, fecha fin, fehca inicio, monto total, DNI, Patente, codigo, devuelto
*/
	cAlquiler(sAdicional _Adicional, tm _FechaInicio, tm _FechaFin, float _MontoTotal, const string _DNI, cVehiculo* _Vehiculo, const string code, bool _Devuelto=false);
	/**
* ~cAlquiler
* destructor de la clase cAlquiler
*/
	virtual ~cAlquiler();
	
#pragma endregion

#pragma region IMPRIMIR & TO STRING
	/**
	* Imprimir
	* imprimir los atributos de la clase en pantalla
	*/
	void Imprimir()const;
	/**
	* To_string
	* crea un string con todos los atributos de la calse
	*/
	string To_string()const;
#pragma endregion

#pragma region GETTERS Y SETTERS

	string getClave() const;
	float getMontoTotal()const;
	tm getFechaFin()const;
	sAdicional getAdicionales()const;
	string getPatente()const;
	void setDevuelto(bool Devuelto = true);
#pragma endregion

};
#endif // !defined(EA_6ADA5A65_C03D_413b_A8C7_BF7E575C2E63__INCLUDED_)
