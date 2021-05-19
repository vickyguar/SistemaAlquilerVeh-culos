//Main

#include "cEmpresa.h"
#include "cAutomovil.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "cMotocicleta.h"

#pragma warning(disable : 4996)


int main() {

	//TODO: CANT ALQUILADOS -> CAMBIAR
	//TODO: ESTATIC TARIFA BASE
	//TODO: MODIFICAR TARIFA BASE -> METODO
	//TODO: GANANCIAS Y PERDIDAS
	//TODO: GET DE LA LISTA DE ALQUILERES -> LISTAR POR VEHICULO

	time_t now = time(NULL); //para obtener hora de SO
	tm FECHA = *localtime(&now);

	cAutomovil* RayoMcqueen = new cAutomovil(eEstadoVehiculo::DISPONIBLE, 1000000, (eAdicionales)0, eColor::ROJO, 0, 0, "RAYO1", "AA111QQ", "LaPoliza1", FECHA);
	cEmpresa* RustEze = new cEmpresa();
	cCliente* JacksonStorm = new cCliente("123456879", "Cliente", "12345673", 40);
	cCamioneta* Mate = new cCamioneta(eEstadoVehiculo::EN_MANTENIMIENTO, 50000, (eAdicionales)0, eColor::GRIS, 0, 0, "TO-MATE", "BB111QQ", "LaPoliza2", FECHA);
	
	RustEze->Adquirir(RayoMcqueen);
	RustEze->Adquirir(Mate);
	RustEze->Alquilar(RayoMcqueen, 20, "12345673", 1);
	
	//PROBAR METODOS DE EMPRESA -> ADQUIRIR /

	return 0;
}