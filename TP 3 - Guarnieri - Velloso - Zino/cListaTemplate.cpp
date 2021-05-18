#include "cListaTemplate.h"

template<class T>
cListaTemplate<T>::cListaTemplate(unsigned int _TAM, bool _Eliminar)
{
	TAM = _TAM;
	CA = 0;
	Eliminar = _Eliminar;

	//Creo la lista dinamica
	Lista = new T * [TAM];
	for (int i = 0; i < TAM; i++) {
		Lista[i] = NULL;
	}
}

template<class T>
cListaTemplate<T>::~cListaTemplate()
{
	if (Lista != NULL) {
		if (Eliminar) {
			for (int i = 0; i < CA; i++)
				delete Lista[i];
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
			int pos = getIndex(newItem->Key);
		}
		catch (exception* ex) {
			Lista[CA++] = newItem;
			delete ex;
		}
		throw new exception("El item ya esta en la lista");
	}	
}

template<class T>
T* cListaTemplate<T>::Quitar(const string Key)
{
	int pos = -1; //Solo para inicializar

	try { pos = getIndex(Key); }
	catch (exception* ex) { 
		string error = ex->what();
		delete ex;
		ex = new exception(("No se puede quitar el item: " + error).c_str());
		throw ex; 
	}

	T* aux = Lista[pos]; 

	for (int i = pos; i < CA - 1; i++)
		Lista[i] = Lista[i + 1]; //Corremos todo una posición para arriba

	Lista[--CA] = NULL; //El ultimo elemento es aux. Tambien hacemos un predecremento de CA

	return aux; //Retornamos aux

}

template<class T>
void cListaTemplate<T>::Eliminar(const string Key)
{
	T* aux = NULL;

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
			int pos = getIndex(newItem->Key);
		}
		catch (exception* ex) {
			Lista[CA++] = &newItem;
			delete ex;
		}
		throw new exception("El item ya esta en la lista");
	}
}

template<class T>
void cListaTemplate<T>::Redimensionar()
{
	T** aux = new T * [2 * TAM]; //La redimensionamos al doble de su tamaño

	for (int i = 0; i < TAM; i++) {
		aux[i] = Lista[i];
		aux[i + TAM] = NULL;

		delete Lista[i];
	}

	delete[] Lista;

	Lista = aux;
	TAM += TAM;
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
		throw new exception(("La posicion " + Index + "no existe en la lista").c_str());
	return Lista[Index];
}

template<class T>
unsigned int cListaTemplate<T>::getIndex(const string Key) const
{
	for (int i = 0; i < CA; i++) {
		if (Lista[i]->Key == Key)
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
	//sobrecarga del cout
}

template<class T>
T* cListaTemplate<T>::operator[](unsigned int pos) {
	return getItem(pos);
}