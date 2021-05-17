///////////////////////////////////////////////////////////
//  cCliente.cpp
//  Implementation of the Class cCliente
//  Created on:      14-may.-2021 15:26:51
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cCliente.h"

cCliente::cCliente(string contacto, string nombre, string dni, unsigned int edad): DNI(dni)
{
	this->Contacto = contacto;
	this->Nombre = nombre;
	this->Edad = edad;
}

cCliente::~cCliente(){
}