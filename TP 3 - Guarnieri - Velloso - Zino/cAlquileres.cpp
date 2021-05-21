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




float cAlquileres::ListarXVehiculo(cVehiculo* Vehiculo, cListaTemplate<cVehiculo>* ListaVehiculos) {

	float gananciaxvehiculo= 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		
		//if (Vehiculo == dynamic_cast<cVehiculo*>(ListaVehiculos->BuscarItem(Lista[i]->getPatente()))) //TODO: el condicional no funca
		//{
		//	cout << Lista[i]->To_string() << endl;
		//	gananciaxvehiculo += Lista[i]->getMontoTotal();
		//}
		//Lista[i]->Imprimir(); cout << endl;
	}
	return gananciaxvehiculo;
	//DUDA sobre estar casteando el tipo cAlquiler con cVehiculo
	// 	   //DUDA: ponerle el dynamic cast al vehiculo que llega por parametro?
	//cAnimal ptr y (dynamic_cast<cMamiferos*>(ptr))->Nombre
}
