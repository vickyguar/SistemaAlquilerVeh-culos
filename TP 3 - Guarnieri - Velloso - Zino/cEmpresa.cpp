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
	_Clientes = new cListaTemplate<cCliente>();
	_Alquileres = new cAlquileres();
	_Vehiculos = new cListaTemplate<cVehiculo>();

	this->ListaAlquileres = _Alquileres;
	this->ListaClientes = _Clientes;
	this->ListaVehiculos = _Vehiculos;
	this->Ganancia = _Ganancia;
}

cEmpresa::~cEmpresa() {
	
	if (ListaClientes != NULL)
		delete ListaClientes;
	if (ListaVehiculos != NULL)
		delete ListaVehiculos;
	if (ListaAlquileres != NULL)
		delete ListaAlquileres;
}

void cEmpresa::Adquirir(cVehiculo* newVehiculo,float PrecioCompra) {
	
	//unsigned int pos; --> esta variable no sirve!!
	if (newVehiculo != NULL) {
		try 
		{
			newVehiculo->setEstado(eEstadoVehiculo::DISPONIBLE); //cambio el estado del vehiculo adquirido
			ListaVehiculos->Agregar(newVehiculo); //intento agregar el vehiculo a la lista de vehiculos de la empresa
		} 
		catch (exception* ex) 
		{
			delete ex;
			ex = new exception(("Error en adquirir: el auto con patente" + newVehiculo->getClave() + " ya existe en la empresa").c_str());
			throw ex;
		}
	}
	Ganancia -= PrecioCompra;
}

void cEmpresa::Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, const string DNI, sAdicional Adicional){
	
	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now); 
	tm FECHA_FIN = FECHA;
	FECHA_FIN.tm_mday += CantDias; //fecha de fin es la misma que la del día de hoy, nada más que con != numero de día
	
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puede alquilar
			throw new exception(("El auto con patente " + Vehiculo->getClave() +
				"no esta disponible y por lo tanto puede ser alquilado").c_str());
		else {
			
			Vehiculo->setEstado(eEstadoVehiculo::ALQUILADO); //si se puede alquilar, le cambio el estado
		}

		if (Adicional.cant1 + Adicional.cant2 > 0) //la cantidad de adicionales solicitada es > 0
			Vehiculo->AnadirAdicionales(Adicional); //agrego los adicionales
		//-----------------------------------------------------------------------------------------
		float MontoTotal =  dynamic_cast<cVehiculo*>(Vehiculo)->CalcularTarifa(CantDias); //calculo el monto total
		//-----------------------------------------------------------------------------------------

		//cAlquiler* aux = new cAlquiler(Adicional, FECHA, FECHA_FIN, MontoTotal, DNI, Vehiculo->getClave(), to_string(ListaAlquileres->getCA() + 1)); //El codigo es la cantidad "nueva" de alquileres resgistrados
		//*ListaAlquileres + aux;
		*ListaAlquileres + new cAlquiler(Adicional, FECHA, FECHA_FIN, MontoTotal, DNI, Vehiculo->getClave(), to_string(ListaAlquileres->getCA() + 1));
		//delete aux;

	}
}

void cEmpresa::Mantenimiento(cVehiculo *Vehiculo, float PrecioMantenimiento){
	if (Vehiculo != NULL) {
		if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puedo poner en mantenimiento
			throw new exception(("El auto con patente " + Vehiculo->getClave() + 
				"no esta disponible y por lo tanto puede someterse a mantenimiento").c_str());
		else {
			cout << endl << Vehiculo->PasosMantenimiento();
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

void cEmpresa::RegistrarDevolucion(cVehiculo* Vehiculo, const string DNI, sAdicional adicionales_devueltos)
{
	if (Vehiculo != NULL) {
		float CobroExtra = 0;
		time_t now = time(NULL); //para obtener hora de SO
		tm FECHA = *localtime(&now);

		//Cantidades de no devueltos
		unsigned int CANT1 = ListaAlquileres->BuscarItem(DNI)->getAdicionales().cant1 - adicionales_devueltos.cant1;
		unsigned int CANT2 = ListaAlquileres->BuscarItem(DNI)->getAdicionales().cant2 - adicionales_devueltos.cant2;


		CobroExtra += (FECHA.tm_mday - ListaAlquileres->BuscarItem(DNI)->getFechaFin().tm_mday) * 5000; // se cobran 5000 por dia de atraso
		CobroExtra += (CANT1 + CANT2) * 3000; //y 3000 por adicionales no devueltos pero se le resta la cantidad de plata destinada a reponer el adicional faltante


		if (CANT1 > 0)
		{
			Ganancia -= float(CANT1 * unsigned int(adicionales_devueltos.Adicional1));
		}
		if (CANT2 > 0)
		{
			Ganancia -= float(CANT2 * unsigned int(adicionales_devueltos.Adicional2));
		}

		Ganancia += CobroExtra;

		//TODO: uso el setDevuelto!!
		ListaAlquileres->BuscarItem(DNI)->setDevuelto();
	}
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

void cEmpresa::ListarxVehiculo(cVehiculo*Vehiculo)
{
	if (Vehiculo != NULL)
		ListaAlquileres->ListarXVehiculo(Vehiculo);
}

cListaTemplate<cVehiculo>* cEmpresa::getListaVehiculos()
{
	return ListaVehiculos;
}

cListaTemplate<cCliente>* cEmpresa::getListaClientes()
{
	return ListaClientes;
}

cAlquileres* cEmpresa::getListaAlquileres()
{
	return ListaAlquileres;
}

float cEmpresa::CalcularGanancia()
{
	Ganancia+=ListaAlquileres->CalcularGanancia();

	return Ganancia;
}
