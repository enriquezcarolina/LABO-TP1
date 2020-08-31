#include "cCamino.h"

cCamino::cCamino(cCiudad* c1, cCiudad* c2)
{
	ciudad1 = c1;
	ciudad2 = c2;
	peajes = rand() % 6;
}

