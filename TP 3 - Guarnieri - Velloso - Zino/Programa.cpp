//Main

#include "cEmpresa.h"
#include "cAutomovil.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "cMotocicleta.h"

#pragma warning(disable : 4996)

//TODOS LOS PRECIOS SON EN U$D :)
bool VerificarAdicionales(cVehiculo* Vehiculo, sAdicional adicional) {

	if (cAutomovil* aux = dynamic_cast<cAutomovil*>(Vehiculo)) {
		if (adicional.Adicional1 != eAdicionales::SILLA_SEGURIDAD)
			return false;
		if (adicional.Adicional2 != (eAdicionales)0)
			return false;
	}

	if (cMotocicleta* aux = dynamic_cast<cMotocicleta*>(Vehiculo)) {
		if (adicional.Adicional1 != eAdicionales::CASCO || adicional.Adicional2 != (eAdicionales)0)
			return false;
		if (adicional.cant1 > 2)
			return false;
	}

	if (cTrafic* aux = dynamic_cast<cTrafic*>(Vehiculo)) {
		if (adicional.Adicional1 != eAdicionales::SILLA_SEGURIDAD ||
			adicional.Adicional2 != eAdicionales::ASIENTOS_REBATIBLES)
			return false;

	}

	if (cCamioneta* aux = dynamic_cast<cCamioneta*>(Vehiculo)) {
		if (adicional.Adicional1 != eAdicionales::SILLA_SEGURIDAD ||
			adicional.Adicional2 != eAdicionales::PORTA_EQUIPAJE)
			return false;
	}

	return true;

}

int main() {

	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now);

	sAdicional adicionales_moto = { eAdicionales::CASCO,eAdicionales::NINGUNO,0,0 }; //para moto
	sAdicional adicionales_auto = { eAdicionales::SILLA_SEGURIDAD,eAdicionales::NINGUNO,0,0 }; //para auto
	sAdicional adicionales_camioneta = { eAdicionales::SILLA_SEGURIDAD,eAdicionales::PORTA_EQUIPAJE,0,0 }; //para camioneta
	sAdicional adicionales_trafic = { eAdicionales::SILLA_SEGURIDAD,eAdicionales::ASIENTOS_REBATIBLES,0,0 }; //para trafic

	sAdicional adicionales_devueltos = { eAdicionales::CASCO, eAdicionales::NINGUNO, 1, 0 };

	cListaTemplate<cCliente>* miListaClientes = new cListaTemplate<cCliente>();
	cAlquileres* miListaAlquileres = new cAlquileres();
	cListaTemplate<cVehiculo>* miListaVehiculos = new cListaTemplate<cVehiculo>();
	
	cEmpresa* miEmpresa = new cEmpresa("23-25723451-12", "Alamo", miListaClientes, miListaVehiculos, miListaAlquileres);

	//AUTOS
	cAutomovil* RayoMcqueen = new cAutomovil(eEstadoVehiculo::DISPONIBLE, 1000, adicionales_auto, eColor::ROJO, "CHASIS1", "AA 111 AA", "POLIZA1", FECHA, 4);
	cAutomovil* Herbie = new cAutomovil(eEstadoVehiculo::DISPONIBLE, 500, adicionales_auto, eColor::BLANCO, "CHASIS2", "AA 222 AB", "POLIZA2", FECHA, 4);
	cAutomovil* BatiMovil = new cAutomovil(eEstadoVehiculo::DISPONIBLE, 5000, adicionales_auto, eColor::NEGRO, "CHASIS3", "AA 333 AC", "POLIZA3", FECHA, 4);

	//CAMIONETAS
	cCamioneta* Mate = new cCamioneta(eEstadoVehiculo::EN_MANTENIMIENTO, 700, adicionales_camioneta, eColor::GRIS, "CHASIS4", "BB 444 AD", "POLIZA4", FECHA, 7);
	cCamioneta* DeLorean = new cCamioneta(eEstadoVehiculo::DISPONIBLE, 750, adicionales_camioneta, eColor::GRIS, "CHASIS5", "BB 555 AE", "POLIZA5", FECHA, 7);
	cCamioneta* March5 = new cCamioneta(eEstadoVehiculo::EN_MANTENIMIENTO, 800, adicionales_camioneta, eColor::BLANCO, "CHASIS6", "BB 666 AF", "POLIZA6", FECHA, 7);

	//TRAFIC
	cTrafic* Dusty = new cTrafic(eEstadoVehiculo::DISPONIBLE, 2000, adicionales_trafic, eColor::AZUL, "CHASIS8", "CC 888 AH", "POLIZA8", FECHA, 10);

	//MOTOS
	cMotocicleta* Vespa = new cMotocicleta(eEstadoVehiculo::DISPONIBLE, 100, adicionales_moto, eColor::NEGRO, "CHASIS9", "DD 999 AI", "POLIZA9", FECHA, 1);
	cMotocicleta* HarleyDavidson = new cMotocicleta(eEstadoVehiculo::DISPONIBLE, 150, adicionales_moto, eColor::NEGRO, "CHASIS10", "DD 110 AJ", "POLIZA10", FECHA, 1);

	//CLIENTES
	cCliente* miCliente1 = new cCliente("555-111-0001", "Marty McFly", "44131411", 20);
	cCliente* miCliente2 = new cCliente("555-111-0002", "Maggie Peyton", "44131412", 30);
	cCliente* miCliente3 = new cCliente("555-111-0003", "Bat Man", "44131413", 40);
	cCliente* miCliente4 = new cCliente("555-111-0004", "Gatubela", "44131414", 50);

	//IMPRIMO DATOS DE EMPRESA
	miEmpresa->Imprimir();

	//LOS VEHICULOS QUE YA SON DE LA EMPRESA -> LOS QUE ESTAN EN MANTENIMIENTO
	try { miEmpresa->getListaVehiculos()->Agregar(Mate); }
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}
	try { miEmpresa->getListaVehiculos()->Agregar(March5); }
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}

	//SE ADQUIEREN VEHICULOS
	try
	{
		miEmpresa->Adquirir(BatiMovil, 50000);
		miEmpresa->Adquirir(DeLorean, 10000);
		miEmpresa->Adquirir(Vespa, 500);
		miEmpresa->Adquirir(Herbie, 20000);
		miEmpresa->Adquirir(HarleyDavidson, 10000);

	}
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}

	cout << *(miEmpresa->getListaVehiculos());

	cout << "--- SE LLEVA A LA MOTO A ARREGLAR ---" << endl;
	miEmpresa->Mantenimiento(Vespa, 50);

	//SE ALQUILAN AUTOS
	try 
	{ 
		miEmpresa->Alquilar(BatiMovil, 7, miCliente3, adicionales_auto);
		miEmpresa->Alquilar(Herbie, 4, miCliente2, adicionales_auto);
		adicionales_auto.cant1 = 1;
		miEmpresa->Alquilar(DeLorean, 30, miCliente1, adicionales_auto);


		cout << endl <<endl << "Usted esta alquilando una moto" << endl;
		cout << "Cuantos cascos quiere? (MAX 2)";
		cin >> adicionales_moto.cant1;

		miEmpresa->Alquilar(HarleyDavidson, 14, miCliente4, adicionales_moto);
	} 
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}
	
	cout << "\n--- LISTA DE ALQUILERES ---" << endl;
	cout << *(miEmpresa->getListaAlquileres());

	cout << "\n--- LISTA POR VEHICULO ---" << endl;
	miEmpresa->ListarxVehiculo();

	cout << "\n--- LISTA POR AUTOMOVILES ---" << endl;
	float GananciaAutos = miEmpresa->ListarxAutomovil();
	printf("Ganancia bruta proveniente de los automoviles: %.2f", GananciaAutos);
	cout << endl;

	cout << "\n--- LISTA POR MOTOCICLETAS ---" << endl;
	float GananciaMotocicletas = miEmpresa->ListarxMotocicleta();
	printf("Ganancia bruta proveniente de las motocicletas: %.2f", GananciaMotocicletas);
	cout << endl;

	cout << "\n--- LISTA POR TRAFIC ---" << endl;
	float GananciaTrafic = miEmpresa->ListarxTrafic();
	printf("Ganancia bruta proveniente de las trafic : %.2f", GananciaTrafic);
	cout << endl;

	cout << "\n--- LISTA POR CAMIONETA ---" << endl;
	float GananciaCamionetas = miEmpresa->ListarxCamioneta();
	printf("Ganancia bruta proveniente de las camionetas: %.2f", GananciaCamionetas);
	cout << endl;

	cout << "\n--- LISTA DE CLIENTES ---" << endl;
	cout << *(miEmpresa->getListaClientes());

	cout << endl <<  "--- GANANCIA BRUTA DE LA EMPRESA ---" << endl;
	cout << "\t" << miEmpresa->GananciaBruta();
	cout << endl;

	cout << "\n--- GANANCIA NETA DE LA EMPRESA ---" << endl;
	cout << "\t" << miEmpresa->GananciaNeta();


	cout << endl << endl;

	delete miEmpresa;
	return 0;
}

