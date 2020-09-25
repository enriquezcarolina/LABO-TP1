#include "cCamino.h"

cCamino::cCamino(cCiudad* ciudad1, cCiudad* ciudad2)
{
	this->ciudad1 = ciudad1;
	this->ciudad2 = ciudad2;
	peajes = rand() % 6;
}

