#pragma once
#include <iostream>
#include <string>
#include "sCoordenadas.h"
using namespace std;

class cCiudad
{
	int poblacion_total;
	sCoordenadas* coordenadas;
public: 
	cCiudad(int pob, sCoordenadas* cor);
	~cCiudad();

};

