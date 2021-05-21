#include "Headers.h"

tm FechaFinAlquiler(unsigned int CantDias, tm FECHA)
{
	unsigned int Variable = CantDias + FECHA.tm_mday;

	if (Variable <= 31)
		FECHA.tm_mday += CantDias;
	else {
		while (Variable > 31) {
			Variable -= 31;
			FECHA.tm_mday = Variable;
			FECHA.tm_mon++;
		}
		while (FECHA.tm_mon > 12) {
			FECHA.tm_mon -= 12;
			FECHA.tm_year++;
		}
	}

	return FECHA;
} 