///////////////////////////////////////////////////////////
//  cEmpresa.cpp
//  Implementation of the Class cEmpresa
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cEmpresa.h"

//cVehiculo era una clase abstracta --> no hay instancias (objetos) de clase vehiculo

#pragma warning(disable : 4996)


cEmpresa::cEmpresa(const string cuit, string nombre, cListaTemplate<cCliente>* _Clientes, cListaTemplate<cVehiculo>* _Vehiculos, cAlquileres* _Alquileres,float _Ganancia): CUIT(cuit)
{
	this->ListaAlquileres = _Alquileres;
	this->ListaClientes = _Clientes;
	this->ListaVehiculos = _Vehiculos;
	this->Nombre = nombre;
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

void cEmpresa::Alquilar(cVehiculo* Vehiculo, unsigned int CantDias, cCliente* Cliente, sAdicional Adicional){
	
	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now); 
	FECHA.tm_mon++;
	tm FECHA_FIN = FechaFinAlquiler(CantDias, FECHA); //fecha de fin es la misma que la del día de hoy, nada más que con != numero de día
	
	if (Vehiculo != NULL) {
		if (Cliente != NULL)
		{
			if (Adicional.Adicional1 == eAdicionales::CASCO && Adicional.cant1 > 2)
				Adicional.cant1 = 2;

			if (Vehiculo->getEstado() != eEstadoVehiculo::DISPONIBLE) //Si no esta disponible, no lo puede alquilar
			{
				throw new exception(("El auto con patente " + Vehiculo->getClave() +
					"no esta disponible y por lo tanto puede ser alquilado").c_str());
				return;
			}
			else {

				Vehiculo->setEstado(eEstadoVehiculo::ALQUILADO); //si se puede alquilar, le cambio el estado
			}

			if (Adicional.cant1 + Adicional.cant2 > 0) //la cantidad de adicionales solicitada es > 0
				Vehiculo->AnadirAdicionales(Adicional); //agrego los adicionales
			//-----------------------------------------------------------------------------------------

			float MontoTotal = dynamic_cast<cVehiculo*>(Vehiculo)->CalcularTarifa(CantDias); //calculo el monto total

			//-----------------------------------------------------------------------------------------
			try
			{
				*ListaClientes + Cliente;
				
			}
			catch (exception* ex) { delete ex; } //el cliente ya existe, pero se puede hacer el alquiler porque puede alquilar otro vehiculo (#)
			try
			{
				*ListaAlquileres + new cAlquiler(Adicional, FECHA, FECHA_FIN, MontoTotal, Cliente->getClave(), Vehiculo, to_string(ListaAlquileres->getCA() + 1));
			}
			catch (exception* ex) { delete ex; } // ya se contempla que sea != NULL y ademas el codigo del alquiler siempre es !=
		}
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

void cEmpresa::RegistrarDevolucion(cVehiculo* Vehiculo, const string code, sAdicional adicionales_devueltos)
{
	if (Vehiculo != NULL) {
		float CobroExtra = 0;
		time_t now = time(NULL); //para obtener hora de SO
		tm FECHA = *localtime(&now);

		//Cantidades de no devueltos
		unsigned int CANT1 = ListaAlquileres->BuscarItem(code)->getAdicionales().cant1 - adicionales_devueltos.cant1;
		unsigned int CANT2 = ListaAlquileres->BuscarItem(code)->getAdicionales().cant2 - adicionales_devueltos.cant2;


		CobroExtra += (FECHA.tm_mday - ListaAlquileres->BuscarItem(code)->getFechaFin().tm_mday) * 5000; // se cobran 5000 por dia de atraso
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

		ListaAlquileres->BuscarItem(code)->setDevuelto(); //El estado del alquiler ahora es vehiculo devuelto
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

	}
}

void cEmpresa::ListarxVehiculo() {
	float aux = ListaAlquileres->ListarXVehiculo();
}

float cEmpresa::ListarxAutomovil() {
	return ListaAlquileres->ListarXAutomovil();
}

float cEmpresa::ListarxCamioneta() {
	return ListaAlquileres->ListarXCamioneta();
}

float cEmpresa::ListarxMotocicleta() {
	return ListaAlquileres->ListarXMotocicleta();
}

float cEmpresa::ListarxTrafic() {
	return ListaAlquileres->ListarXTrafic();
}


float cEmpresa::GananciaBruta()
{
	return ListaAlquileres->CalcularGanancia();
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

string cEmpresa::To_String() const
{
	string output = "Nombre: " + Nombre + "\nCUIT: " + CUIT + "\nGanancia: " + to_string(Ganancia);
	return output;
}

void cEmpresa::Imprimir() const
{
	cout << To_String();
}

float cEmpresa::GananciaNeta()
{
	Ganancia += ListaAlquileres->CalcularGanancia();

	return Ganancia;
}
