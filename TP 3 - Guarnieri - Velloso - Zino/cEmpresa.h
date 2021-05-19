///////////////////////////////////////////////////////////
//  cEmpresa.h
//  Implementation of the Class cEmpresa
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_1AE703F9_42E0_4b65_A672_7DE8013B46E2__INCLUDED_)
#define EA_1AE703F9_42E0_4b65_A672_7DE8013B46E2__INCLUDED_

#include "cVehiculo.h"
#include "cCliente.h"
#include "cAlquileres.h"
#include "cListaTemplate.h"

class cEmpresa 
{
private:

	cListaTemplate<class cCliente>* ListaClientes;
	cListaTemplate<class cVehiculo>* ListaVehiculos;
	cAlquileres* ListaAlquileres;

public:
	
	cEmpresa(cListaTemplate<cCliente>* _Clientes = NULL, cListaTemplate<cVehiculo>* _Vehiculos = NULL, cAlquileres * _Alquileres = NULL);
	virtual ~cEmpresa();
	void Adquirir(cVehiculo* newVehiculo);
	void Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, const string DNI, unsigned int CantAdicionales = 0);
	void Mantenimiento(cVehiculo* Vehiculo);
	void RetirarCirculacion(cVehiculo* Vehiculo);

};
#endif // !defined(EA_1AE703F9_42E0_4b65_A672_7DE8013B46E2__INCLUDED_)
