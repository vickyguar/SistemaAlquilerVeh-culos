///////////////////////////////////////////////////////////
//  cAlquileres.cpp
//  Implementation of the Class cAlquileres
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cAlquileres.h"


cAlquileres::cAlquileres(unsigned int _TAM, bool _Delete):cListaTemplate<class cAlquiler>(_TAM,_Delete){

}

cAlquileres::~cAlquileres(){

}


float cAlquileres::CalcularGanancia(){
	float Ganancia= 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista[i] != NULL&&Lista[i]->getDevuelto())
			Ganancia += Lista[i]->getMontoTotal(); //se suman todos los alquileres que ya han sido pagados
	}
	return Ganancia;
}


void cAlquileres::ListarXVehiculo(cVehiculo*Vehiculo){
	
	for (unsigned int i = 0; i < CA; i++)
	{
		if (dynamic_cast<cVehiculo*>(Vehiculo) == dynamic_cast<cVehiculo*>(Lista[i]))
			Lista[i]->Imprimir(); cout << endl;
		

	}
	//DUDA sobre estar casteando el tipo cAlquiler con cVehiculo
	//cAnimal ptr y (dynamic_cast<cMamiferos*>(ptr))->Nombre
}