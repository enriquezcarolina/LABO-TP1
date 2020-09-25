#pragma once
#include <iostream>
#include <string>
#include "sCoordenadas.h"

#define _USE_MATH_DEFINES
#include "math.h"
using namespace std;

class cCiudad
{
	string nombre;
	int poblacion_total;
	sCoordenadas* coordenadas;

public: 
	cCiudad(string nombre, int poblacion_tot, float longitud, float latitud);
	cCiudad();
	~cCiudad();
	string tostring();
	float calculardistancia(cCiudad* destino);
	string getnombre(){ return nombre; }
};

