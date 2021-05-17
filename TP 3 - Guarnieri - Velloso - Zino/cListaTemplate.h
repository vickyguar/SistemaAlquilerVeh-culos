#pragma once

#include <iostream>
#include <string>

#define NMAX 50

using namespace std;

//Importante: Damian hizo algo distinto! creo una clase template!

template<class T>
class cListaTemplate
{
protected:
	T** Lista;
	unsigned int CA, TAM;
	bool Eliminar;
	void Redimensionar();

public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cListaTemplate(unsigned int _TAM = NMAX, bool _Eliminar = true);
	virtual ~cListaTemplate();
#pragma endregion

#pragma region AGREGAR, QUITAR, ELIMINAR
	void Agregar(T* newItem);
	T* Quitar(const string Key);
	void Eliminar(const string Key);

#pragma endregion

#pragma region BUSCAR
	T* BuscarItem(const string Key);
	T* BuscarXPos(unsigned int Index);
#pragma endregion

#pragma region GETTERS
	unsigned int getIndex(const string Key)const;
	unsigned int getCA()const;
	unsigned int getTAM()const;
#pragma endregion

	void Listar()const; //Imprime en pantalla la lista -> HAY QUE HACER UN TO STRING DE LOS ELEMENTOS!
	/*Damian tiene a Listar asi: DESPUES MIRAR!
	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();// SOBRECARGA DEL COUT
	}
	*/


};


