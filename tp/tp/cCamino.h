#pragma once
#include <iostream>
#include <string>
#include "cCiudad.h"

class cCamino
{
	cCiudad* ciudad1;
	cCiudad* ciudad2;
	int peajes;

public:
	cCamino(cCiudad* c1, cCiudad* c2);
	int getpeajes(){return peajes;}

};

