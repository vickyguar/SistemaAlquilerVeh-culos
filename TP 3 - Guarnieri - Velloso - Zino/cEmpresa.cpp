///////////////////////////////////////////////////////////
//  cEmpresa.cpp
//  Implementation of the Class cEmpresa
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cEmpresa.h"

//cVehiculo era una clase abstracta --> no hay instancias (objetos) de clase vehiculo

#pragma warning(disable : 4996)


cEmpresa::cEmpresa(cListaTemplate<cCliente>* _Clientes, cListaTemplate<cVehiculo>* _Vehiculos, cAlquileres* _Alquileres,float _Ganancia)
{
	ListaAlquileres = _Alquileres;

	ListaClientes = _Clientes;

	ListaVehiculos = _Vehiculos;

	Ganancia = _Ganancia;
}

cEmpresa::~cEmpresa() {
	if (ListaAlquileres != NULL)
		delete ListaAlquileres;
	if (ListaClientes != NULL)
		delete ListaClientes;
	if (ListaVehiculos != NULL)
		delete ListaVehiculos;
}

void cEmpresa::Adquirir(cVehiculo* newVehiculo,float PrecioCompra) {
	
	unsigned int pos;
	if (newVehiculo != NULL) {
		try { pos = ListaVehiculos->getIndex(newVehiculo->getClave()); }
		catch (exception* ex) {
			delete ex; //si entra al catch, significa que no existe
			newVehiculo->setEstado(eEstadoVehiculo::DISPONIBLE);
			try{ ListaVehiculos->Agregar(newVehiculo); }
			catch (exception* ex) {
				ex = new exception(("Error en adquirir: el auto con patente" + newVehiculo->getClave() + " ya existe en la empresa").c_str());
				throw ex;
			}
		}
	}
	Ganancia -= PrecioCompra;
}

void cEmpresa::Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, const string DNI, unsigned int CantAdicionales){
	
	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now); 
	tm FECHA_FIN = FECHA;
	FECHA_FIN.tm_mday += CantDias;
	
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puedo poner en mantenimiento
			throw new exception(("El auto con patente " + Vehiculo->getClave() +
				"no esta disponible y por lo tanto puede ser alquilado").c_str());
		else {
			
			Vehiculo->setEstado(eEstadoVehiculo::ALQUILADO);
		}

		if (CantAdicionales > 0)
			Vehiculo->AnadirAdicionales(CantAdicionales);
		//-----------------------------------------------------------------------------------------
		float MontoTotal =  CantDias * Vehiculo->CalcularTarifas();

		//-----------------------------------------------------------------------------------------

		cAlquiler* aux = new cAlquiler(CantAdicionales, FECHA, FECHA_FIN, CalcularTarifa(CantDias), DNI, Vehiculo->getClave());
		ListaAlquileres->AgregarXCopia(*aux);
		delete aux;

	}
}

void cEmpresa::Mantenimiento(cVehiculo *Vehiculo, float PrecioMantenimiento){
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puedo poner en mantenimiento
			throw new exception(("El auto con patente " + Vehiculo->getClave() + 
				"no esta disponible y por lo tanto puede someterse a mantenimiento").c_str());
		else {
			cout << Vehiculo->PasosMantenimiento();
			Vehiculo->setEstado(eEstadoVehiculo::EN_MANTENIMIENTO);

			//---------------------------------------------------------------------------------------
			time_t now = time(NULL); //para obtener hora de SO
			tm FECHA = *localtime(&now);
			Vehiculo->setFechaUltMantenimiento(FECHA); //cambio la fecha de ultimo mantenimiento
			//---------------------------------------------------------------------------------------

		}
		Ganancia -= PrecioMantenimiento;
	}
	
}

void cEmpresa::RegistrarDevolucion(cVehiculo* Vehiculo, const string DNI, unsigned int CantAdicionales)
{
	float CobroExtra = 0;
	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now);
	
	CobroExtra += (ListaAlquileres->BuscarItem(DNI)->getAdicionales() - CantAdicionales) * 3000; //se cobran 3000 por adicionales no devueltos
	CobroExtra += (FECHA.tm_mday - ListaAlquileres->BuscarItem(DNI)->getFechaFin().tm_mday) * 5000; // y 5000 por dia de atraso
	//TODO: PREDIDA POR FALTa de devolucion de adicionales . Ganancia-=
	Ganancia += CobroExtra;

}

void cEmpresa::RetirarCirculacion(cVehiculo* Vehiculo){
	unsigned int pos = -1;
	if (Vehiculo != NULL) {
		try { pos = ListaVehiculos->getIndex(Vehiculo->getClave()); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("No se puede quitar de circulacion al vehiculo " + error).c_str());
			throw ex;
		}
		Vehiculo->setEstado(eEstadoVehiculo::FUERA_CIRCULACION); 
		//TODO: hay que sacarlo de la lista?
		//ListaVehiculos->Quitar(Vehiculo->getPatente());
	}
}

float cEmpresa::CalcularGanancia()
{
	Ganancia+=ListaAlquileres->CalcularGanancia();

	return Ganancia;
}
