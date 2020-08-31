#pragma once
#include <iostream>
#include <string>
using namespace std;

class sCoordenadas
{
	float latitud;
	float longitud;

public: 
	sCoordenadas(float la, float lo);
	sCoordenadas();
	string tostring();
	float getLatitud(){ return latitud;}
	float getLongitud(){ return longitud;}
};

