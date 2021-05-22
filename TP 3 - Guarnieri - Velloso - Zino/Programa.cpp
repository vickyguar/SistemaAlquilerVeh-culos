//Main

#include "cEmpresa.h"
#include "cAutomovil.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "cMotocicleta.h"

#pragma warning(disable : 4996)

//TODOS LOS PRECIOS SON EN U$D :)

int main() {

	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now);

	sAdicional adicionales_moto = { eAdicionales::CASCO,eAdicionales::NINGUNO,0,0 }; //para moto
	sAdicional adicionales_auto = { eAdicionales::SILLA_SEGURIDAD,eAdicionales::NINGUNO,0,0 }; //para auto
	sAdicional adicionales_camioneta = { eAdicionales::SILLA_SEGURIDAD,eAdicionales::PORTA_EQUIPAJE,0,0 }; //para camioneta
	sAdicional adicionales_trafic = { eAdicionales::SILLA_SEGURIDAD,eAdicionales::ASIENTOS_REBATIBLES,0,0 }; //para trafic

	sAdicional adicionales_devueltos = { eAdicionales::CASCO, eAdicionales::NINGUNO, 1, 0 };

	cEmpresa* Alamo = new cEmpresa();

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
	cCliente* miCliente4 = new cCliente("555-111-0004", "Gatuvela", "44131414", 50);

	//LOS VEHICULOS QUE YA SON DE LA EMPRESA -> LOS QUE ESTAN EN MANTENIMIENTO
	try { Alamo->getListaVehiculos()->Agregar(Mate); }
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}
	try { Alamo->getListaVehiculos()->Agregar(March5); }
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}

	//SE ADQUIEREN VEHICULOS
	try
	{
		Alamo->Adquirir(BatiMovil, 50000);
		Alamo->Adquirir(DeLorean, 10000);
		Alamo->Adquirir(Vespa, 500);
		Alamo->Adquirir(Herbie, 20000);
		Alamo->Adquirir(HarleyDavidson, 10000);

	}
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}

	cout << *(Alamo->getListaVehiculos());

	cout << "--- SE LLEVA A LA MOTO A ARREGLAR ---" << endl;
	Alamo->Mantenimiento(Vespa, 50);

	//SE ALQUILAN AUTOS
	try { Alamo->getListaClientes()->Agregar(miCliente3); }
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}

	try 
	{ 
		Alamo->Alquilar(BatiMovil, 7, miCliente3->getClave(), adicionales_auto);
		Alamo->Alquilar(Herbie, 4, miCliente2->getClave(), adicionales_auto);
		adicionales_auto.cant1 = 1;
		Alamo->Alquilar(DeLorean, 30, miCliente1->getClave(), adicionales_auto);

		cout << endl <<endl << "Usted esta alquilando una moto" << endl;
		cout << "Cuantos cascos quiere? ";
		cin >> adicionales_moto.cant1;

		Alamo->Alquilar(HarleyDavidson, 14, miCliente4->getClave(), adicionales_moto);

	} 
	catch (exception* ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}
	
	cout << "\n--- LISTA DE ALQUILERES ---" << endl;
	Alamo->getListaAlquileres()->Listar();
	cout << "\n--- LISTA POR VEHICULO ---" << endl;
	Alamo->ListarxVehiculo();

	cout << "\n--- LISTA POR AUTOMOVILES ---" << endl;
	float GananciaAutos = Alamo->ListarxAutomovil();
	printf("Ganancia bruta proveniente de los automoviles: %.2f", GananciaAutos);
	cout << endl;

	cout << "\n--- LISTA POR MOTOCICLETAS ---" << endl;
	float GananciaMotocicletas = Alamo->ListarxMotocicleta();
	printf("Ganancia bruta proveniente de las motocicletas: %.2f", GananciaMotocicletas);
	cout << endl;

	cout << "\n--- LISTA POR TRAFIC ---" << endl;
	float GananciaTrafic = Alamo->ListarxTrafic();
	printf("Ganancia bruta proveniente de las trafic : %.2f", GananciaTrafic);
	cout << endl;

	cout << "\n--- LISTA POR CAMIONETA ---" << endl;
	float GananciaCamionetas = Alamo->ListarxCamioneta();
	printf("Ganancia bruta proveniente de las camionetas: %.2f", GananciaCamionetas);
	cout << endl;

	cout << "--- GANANCIA BRUTA DE LA EMPRESA ---" << endl;
	cout << "\t" << Alamo->GananciaBruta();
	cout << endl;

	cout << "\n--- GANANCIA NETA DE LA EMPRESA ---" << endl;
	cout << "\t" << Alamo->GananciaNeta();


	cout << endl << endl;

	delete Alamo;
	return 0;
}

