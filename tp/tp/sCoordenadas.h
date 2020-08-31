#pragma once
#include <iostream>
#include <string>
using namespace std;

class sCoordenadas
{
	double latitud;
	double longitud;

public: 
	sCoordenadas(double la, double lo);
	sCoordenadas();
	string tostring();
	double getLatitud(){ return latitud;}
	double getLongitud(){ return longitud;}
};

