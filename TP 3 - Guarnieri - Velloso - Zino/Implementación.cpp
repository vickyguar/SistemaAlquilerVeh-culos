#include "Headers.h"

tm FechaFinAlquiler(unsigned int CantDias, tm FECHA)
{
	unsigned int Variable = CantDias + FECHA.tm_mday;
	//Caso 1: la cantidad de días hace que la fecha cambie de mes
	if (Variable > 31) {
		FECHA.tm_mon = FECHA.tm_mon + 1;
		FECHA.tm_mday = (CantDias + FECHA.tm_mday) - 31;
	}

	return FECHA;
} 