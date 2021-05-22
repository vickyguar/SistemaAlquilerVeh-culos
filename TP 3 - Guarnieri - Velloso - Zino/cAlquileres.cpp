///////////////////////////////////////////////////////////
//  cAlquileres.cpp
//  Implementation of the Class cAlquileres
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAlquileres.h"


cAlquileres::cAlquileres(unsigned int _TAM, bool _Delete):cListaTemplate<cAlquiler>(_TAM,_Delete){

}

cAlquileres::~cAlquileres()
{
}

float cAlquileres::CalcularGanancia(){
	float Ganancia= 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista[i] != NULL)
			Ganancia += Lista[i]->getMontoTotal(); //se suman todos los alquileres el pago se realiza al momento de alquilar
	}
	return Ganancia;
}




float cAlquileres::ListarXAutomovil() {

	float gananciaxvehiculo = 0; //Acumulador
	unsigned int cont; //contador
	cout << endl << "------ Automoviles ------" << endl;
	cont = 0;

	for (unsigned int i = 0; i < CA; i++)
	{
		if (cAutomovil* aux = dynamic_cast<cAutomovil*>(Lista[i]->getVehiculo()))
		{
			cout << Lista[i]->To_string() << endl;
			gananciaxvehiculo += Lista[i]->getMontoTotal();
			cont++;
		}
	}

	cout << (cont == 0 ? "No hay automoviles alquilados\n" : " \n");
	return gananciaxvehiculo;
}

float cAlquileres::ListarXMotocicleta() {

	float gananciaxvehiculo = 0; //Acumulador
	unsigned int cont; //contador
	cout << endl << "------ Motocicleta ------" << endl;
	cont = 0;

	for (unsigned int i = 0; i < CA; i++)
	{
		if (cMotocicleta* aux = dynamic_cast<cMotocicleta*>(Lista[i]->getVehiculo()))
		{
			cout << Lista[i]->To_string() << endl;
			gananciaxvehiculo += Lista[i]->getMontoTotal();
			cont++;
		}
	}

	cout << (cont == 0 ? "No hay motocicletas alquiladas\n" : " \n");
	return gananciaxvehiculo;
}

float cAlquileres::ListarXCamioneta() {

	float gananciaxvehiculo = 0; //Acumulador
	unsigned int cont; //contador
	cout << endl << "------ Camionetas ------" << endl;
	cont = 0;

	for (unsigned int i = 0; i < CA; i++)
	{
		if (cCamioneta* aux = dynamic_cast<cCamioneta*>(Lista[i]->getVehiculo()))
		{
			cout << Lista[i]->To_string() << endl;
			gananciaxvehiculo += Lista[i]->getMontoTotal();
			cont++;
		}
	}

	cout << (cont == 0 ? "No hay camionetas alquiladas\n" : " \n");
	return gananciaxvehiculo;
}

float cAlquileres::ListarXTrafic() {

	float gananciaxvehiculo = 0; //Acumulador
	unsigned int cont; //contador
	cout << endl << "------ Trafics ------" << endl;
	cont = 0;

	for (unsigned int i = 0; i < CA; i++)
	{
		if (cTrafic* aux = dynamic_cast<cTrafic*>(Lista[i]->getVehiculo()))
		{
			cout << Lista[i]->To_string() << endl;
			gananciaxvehiculo += Lista[i]->getMontoTotal();

			cont++;
		}
	}

	cout << (cont == 0 ? "No hay trafics alquiladas\n" : " \n");
	return gananciaxvehiculo;
}





float cAlquileres::ListarXVehiculo() {

	return (ListarXAutomovil() + ListarXCamioneta() + ListarXMotocicleta() + ListarXTrafic());
}

