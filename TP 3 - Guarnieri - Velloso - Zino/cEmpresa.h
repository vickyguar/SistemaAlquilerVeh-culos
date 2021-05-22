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
	string CUIT;
	string Nombre;
	float Ganancia; //ganancia de la empresa

public:
	
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cEmpresa 
	* constructor de la clase empresa
	*/
	cEmpresa(string cuit, string nombre, cListaTemplate<cCliente>* _Clientes = NULL, cListaTemplate<cVehiculo>* _Vehiculos = NULL, cAlquileres* _Alquileres = NULL, float _Ganancia = 0);
	/**
	* ~cEmpresa
	* destructor de la clase empresa
	*/
	virtual ~cEmpresa();
#pragma endregion

#pragma region METODOS
	/**
	* Adquirir
	* agrega un vehiculo a la lista de vehiculos de la empresa
	* @param vehiculo*, precio de compra
	*/
	void Adquirir(cVehiculo* newVehiculo, float PrecioCompra);
	/**
	* Alquilar
	* cambia el estado del vehiculo. Agrega el alquiler a la lista de alquileres
	* @param vehiculo*, cantidad de dias, DNI, adicionales
	*/
	void Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, const string DNI, sAdicional adicional);
	/**
	* RegistrarDevolucion
	* registra la devolucion del vehiculo. Si se pasa de dias, se le cobra una multa
	* @param vehiculo*, precio de compra
	*/
	void RegistrarDevolucion(cVehiculo* Vehiculo, const string code, sAdicional adicionales_devueltos); 
	/**
	* Mantenimiento 
	* cambia el estado del vehiculo a "en mantenimiento" y le cobra a la empresa (perdida)
	*/
	void Mantenimiento(cVehiculo* Vehiculo, float GastoMantenimiento);
	/**
	* RetirarCirculacion 
	* elimina a un vehiculo de la lista de vehiculos de la empresa
	*/
	void RetirarCirculacion(cVehiculo* Vehiculo);
#pragma endregion

#pragma region LISTAR
	void ListarxVehiculo();
	float ListarxAutomovil();
	float ListarxCamioneta();
	float ListarxMotocicleta();
	float ListarxTrafic();
#pragma endregion

#pragma region GANANCIAS
	float GananciaNeta();
	float GananciaBruta();
#pragma endregion

#pragma region GETTES & SETTERS
	cListaTemplate<cVehiculo>* getListaVehiculos();
	cListaTemplate<cCliente>* getListaClientes();
	cAlquileres* getListaAlquileres();
#pragma endregion

};
#endif // !defined(EA_1AE703F9_42E0_4b65_A672_7DE8013B46E2__INCLUDED_)
