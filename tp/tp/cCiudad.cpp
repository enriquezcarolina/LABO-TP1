#include "cCiudad.h"
#include "sCoordenadas.h"

cCiudad::cCiudad(int pob, sCoordenadas* cor)
{
	poblacion_total = pob;
	coordenadas = cor;
}

cCiudad::~cCiudad()
{
	delete coordenadas;
}
