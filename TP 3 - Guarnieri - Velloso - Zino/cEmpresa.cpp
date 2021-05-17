///////////////////////////////////////////////////////////
//  cEmpresa.cpp
//  Implementation of the Class cEmpresa
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cEmpresa.h"

//cVehiculo era una clase abstracta --> no hay instancias (objetos) de clase vehiculo




cEmpresa::cEmpresa()
{
	ListaAlquileres = new cAlquileres();
	ListaClientes = new cListaTemplate<cCliente>();
	ListaVehiculos = new cListaTemplate<cVehiculo>();
}

cEmpresa::~cEmpresa() {
	if (ListaAlquileres != NULL)
		delete ListaAlquileres;
	if (ListaClientes != NULL)
		delete ListaClientes;
	if (ListaVehiculos != NULL)
		delete ListaVehiculos;
}

void cEmpresa::Adquirir(cVehiculo* newVehiculo) {
	
	unsigned int pos = -1;
	if (newVehiculo != NULL) {
		try { pos = ListaVehiculos->getIndex(newVehiculo->getPatente()); }
		catch (exception* ex) {
			delete ex; //si entra al catch, significa que no existe
			ListaVehiculos->Agregar(newVehiculo);
			newVehiculo->setEstado(eEstadoVehiculo::DISPONIBLE);
		}
		throw new exception(("El auto con patente" + newVehiculo->getPatente() + " ya existe en la empresa").c_str());
	}
}

void cEmpresa::Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, const string DNI, unsigned int CantAdicionales = 0){
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puedo poner en mantenimiento
			throw new exception(("El auto con patente " + Vehiculo->getPatente() +
				"no esta disponible y por lo tanto puede ser alquilado").c_str());
		else {
			
			Vehiculo->setEstado(eEstadoVehiculo::ALQUILADO);
		}

		if (CantAdicionales > 0)
			Vehiculo->AnadirAdicionales(CantAdicionales);

		time_t now = time(NULL); //para obtener hora de SO
		tm FECHA = *localtime(&now); //inicializo la fecha (fechaUltVIsita)

		cAlquiler* aux = new cAlquiler(CantAdicionales, FECHA, Vehiculo->CalcularTarifa(CantDias), DNI, Vehiculo->getPatente());




	}
}

void cEmpresa::Mantenimiento(cVehiculo *Vehiculo){
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puedo poner en mantenimiento
			throw new exception(("El auto con patente " + Vehiculo->getPatente() + 
				"no esta disponible y por lo tanto puede someterse a mantenimiento").c_str());
		else {
			cout << Vehiculo->PasosMantenimiento();
			Vehiculo->setEstado(eEstadoVehiculo::EN_MANTENIMIENTO);
		}
	}
	
}

void cEmpresa::RetirarCirculacion(cVehiculo* Vehiculo){

}
