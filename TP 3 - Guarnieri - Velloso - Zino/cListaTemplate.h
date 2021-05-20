#pragma once

#include <iostream>
#include <string>
#include <ostream>

#define NMAX 50

using namespace std;

//Importante: Damian hizo algo distinto! creo una clase template!

template<class T>
class cListaTemplate
{
protected:
	T** Lista;
	unsigned int CA, TAM;
	bool Delete;

public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cListaTemplate(unsigned int _TAM = NMAX, bool _Delete = true);
	virtual ~cListaTemplate();
#pragma endregion

#pragma region AGREGAR, QUITAR, ELIMINAR
	void Agregar(T* newItem);
	T* Quitar(const string Key);
	void Eliminar(const string Key);
	void AgregarXCopia(T newItem); //Agrego por copia

#pragma endregion
	void Redimensionar();

#pragma region BUSCAR
	T* BuscarItem(const string Key);
	T* BuscarXPos(unsigned int Index);
#pragma endregion

#pragma region GETTERS
	unsigned int getIndex(const string Key)const;
	unsigned int getCA()const;
	unsigned int getTAM()const;
#pragma endregion

	void Listar()const; 
	//Imprime en pantalla la lista -> HAY QUE HACER UN TO STRING DE LOS ELEMENTOS!
	/*Damian tiene a Listar asi: DESPUES MIRAR!
	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();// SOBRECARGA DEL COUT
	}
	*/

#pragma region SOBRECARGA
	T* operator[](unsigned int pos);
	friend cListaTemplate<T>& operator+(cListaTemplate<T>& lista, T* newItem);
	friend ostream& operator<<(ostream& out, T& obj);

#pragma endregion

};

template<class T>
cListaTemplate<T>::cListaTemplate(unsigned int _TAM, bool _Delete)
{
	TAM = _TAM;
	CA = 0;
	Delete = _Delete;

	//Creo la lista dinamica
	Lista = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++) {
		Lista[i] = NULL;
	}
}

template<class T>
cListaTemplate<T>::~cListaTemplate()
{
	if (Lista != NULL) {
		if (Delete) {
			for (unsigned int i = 0; i < CA; i++)
			{
				if(Lista[i]!= NULL)
					delete Lista[i];
			}
		}
		delete[] Lista;
	}
}

template<class T>
void cListaTemplate<T>::Agregar(T* newItem)
{
	if (Lista != NULL && newItem != NULL) {

		if (CA == TAM) //Si la cantidad actual es igual al tamaño máximo
			Redimensionar(); //Redimensiono la lista

		try {
			int pos = getIndex(newItem->getClave()); //busco el elemento en la lista
		}
		catch (exception* ex) { //si el elemento no existe
			delete ex;
			Lista[CA] = newItem; //lo agrego a la lista
			CA++;
			return;
		}
		throw new exception("El item ya esta en la lista");
	}
}

template<class T>
T* cListaTemplate<T>::Quitar(const string Key)
{
	int pos = -1; //Solo para inicializar

	try { pos = getIndex(Key); } //busco el elemento
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("No se puede quitar el item: " + error).c_str());
		throw ex;
	}

	T* aux = Lista[pos]; //me lo guardo si lo encuentra

	for (int i = pos; i < CA - 1; i++)
		Lista[i] = Lista[i + 1]; //Corremos todo una posición para arriba

	Lista[--CA] = NULL; //El ultimo elemento es aux. Tambien hacemos un predecremento de CA

	return aux; //Retornamos aux

}

template<class T>
void cListaTemplate<T>::Eliminar(const string Key)
{
	T* aux = NULL; //auxiliar

	if (Lista != NULL) {
		try { aux = Quitar(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("No se puede eliminar el item: " + error).c_str());
			throw ex;
		}
	}
	delete aux; //Eliminamos
}

template<class T>
void cListaTemplate<T>::AgregarXCopia(T newItem)
{
	if (Lista != NULL) {

		if (CA == TAM) //Si la cantidad actual es igual al tamaño máximo
			Redimensionar(); //Redimensiono la lista

		try {
			int pos = getIndex(newItem.getClave()); //TODO: Fijarse
		}
		catch (exception* ex) {
			Lista[CA++] = &newItem;
			//Lista + newItem; //SObrecarga de +
			delete ex;
			return;
		}
		throw new exception("El item ya esta en la lista");
	}
}

template<class T>
void cListaTemplate<T>::Redimensionar()
{
	unsigned int n = 2 * TAM;
	T** aux = new T * [n]; //La redimensionamos al doble de su tamaño

	//--------------------------------------------
	for (unsigned int i = 0; i < TAM; i++) {
		aux[i] = Lista[i]; //me copio el elemento
		aux[i + TAM] = NULL; //los otros los pongo en NULL
	}
	//--------------------------------------------

	delete[] Lista; //borro el puntero grande

	Lista = aux; //Lista ahora apunta a la lista redimencionada
	TAM += TAM; //cambio el TAM 
}

template<class T>
T* cListaTemplate<T>::BuscarItem(const string Key)
{
	int pos = -1; //Solo para inicializar

	if (Lista != NULL) {
		try { pos = getIndex(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("Error al buscar item: " + error).c_str());
			throw ex;
		}
	}

	return Lista[pos];
}

template<class T>
T* cListaTemplate<T>::BuscarXPos(unsigned int Index)
{
	if (Index > CA)
		throw new exception(("La posicion " + to_string(Index) + "no existe en la lista").c_str());
	return Lista[Index];
}

template<class T>
unsigned int cListaTemplate<T>::getIndex(const string Key) const
{
	for (unsigned int i = 0; i < CA; i++) { //POR ACA TIRA ERROR
		if (Lista[i]->getClave() == Key) //EL ->KEY debe llamarse igual pa todas para que no tire error
			return i;
	}

	throw new exception((Key + " El item no existe").c_str());
}

template<class T>
unsigned int cListaTemplate<T>::getCA() const
{
	return CA;
}

template<class T>
unsigned int cListaTemplate<T>::getTAM() const
{
	return TAM;
}

template<class T>
void cListaTemplate<T>::Listar() const
{
	for (unsigned int i = 0; i < CA; i++)
	{
		//cout << "\n\t# " << i + 1 << endl;
		cout << Lista[i]->To_string(); //TODO: se rompe -> sobrecarga del To_String
	}
}

template<class T>
T* cListaTemplate<T>::operator[](unsigned int pos) {
	return BuscarItem(pos);
}

template<class T>
cListaTemplate<T>& operator+(cListaTemplate<T>& lista, T* newItem)
{
	try { lista.Agregar(newItem); }
	catch (exception* ex) {
		delete ex; //significa que no existe!
	}
	return lista;
}

//template<class T>
//ostream& operator<<(ostream& out, T& obj)
//{
//	out << obj.To_String();
//	return out;
//}

//bool operator==(string clave)
//{
//	if (clave == DNI)
//		return true;
//	if (clave == Nombre)
//		return true;
//	if (clave == Apellido)
//		return true;
//	return false;
//}