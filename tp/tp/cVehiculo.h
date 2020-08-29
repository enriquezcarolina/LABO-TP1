#pragma once 
#include <iostream>
#include <string>
#include "math.h"
#include "cCiudad.h"
using namespace std;

class cVehiculo
{
	cCiudad* ubicacion_actual;
	int dist_recorrida;
	const int dist_mantenimiento;
	const int capacidad_tanque;
	const int consumo; //cant de nafta que consume c/100km
	int precio;
	const string modelo, marca, anio_lanzamiento;
	int nafta_actual;

public: 
	cVehiculo(cCiudad* ua, const int dism, const int cp, const int consumo,int prec, const string m, const string a, const string mo);
	
	bool recargartanque(int cantnafta);
	void viajar(cCiudad* destino); //sumar dist_recorrida
	void mantenimiento(); //mantenimiento cada dist_mantenimiento
	bool verificarnaftasuficiente(float distancia); //verificar que la nafta alcanza para realizar el viaje

	string tostring();
	void imprimirpantalla();

	~cVehiculo();

};

