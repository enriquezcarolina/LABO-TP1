#pragma once
#include <iostream>
#include <string>
#include "sCoordenadas.h"
#include "math.h"
using namespace std;

class cCiudad
{
	string nombre;
	int poblacion_total;
	sCoordenadas* coordenadas;

public: 

	cCiudad(string nom, int pob, sCoordenadas* cor);
	~cCiudad();
	string tostring();
	float calculardistancia(cCiudad* destino);

};

