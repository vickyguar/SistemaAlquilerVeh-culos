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

class cEmpresa 
{
private:

	cListaTemplate<cCliente>* ListaClientes; //lista de clientes
	cListaTemplate<cVehiculo>* ListaVehiculos; //lista de vehiculos
	cAlquileres* ListaAlquileres; //lista de alquileres
	float Ganancia; //ganancia de la empresa

public:
	
#pragma region CONSTRUCTORES & DESTRUCTORES
	cEmpresa(cListaTemplate<cCliente>* _Clientes = NULL, cListaTemplate<cVehiculo>* _Vehiculos = NULL, cAlquileres* _Alquileres = NULL, float _Ganancia = 0);
	virtual ~cEmpresa();
#pragma endregion

#pragma region METODOS
	void Adquirir(cVehiculo* newVehiculo, float PrecioCompra);
	void Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, const string DNI, sAdicional adicional);
	void RegistrarDevolucion(cVehiculo* Vehiculo, const string DNI, sAdicional adicionales_devueltos);
	void Mantenimiento(cVehiculo* Vehiculo, float GastoMantenimiento);
	void RetirarCirculacion(cVehiculo* Vehiculo);
	void ListarxVehiculo(cVehiculo* Vehiculo);
	float CalcularGanancia();
#pragma endregion

#pragma region GETTES & SETTERS
	cListaTemplate<cVehiculo>* getListaVehiculos();
	cListaTemplate<cCliente>* getListaClientes();
	cAlquileres* getListaAlquileres();
#pragma endregion

};
#endif // !defined(EA_1AE703F9_42E0_4b65_A672_7DE8013B46E2__INCLUDED_)
