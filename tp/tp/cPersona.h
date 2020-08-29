#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "cCiudad.h"
#include "sFecha.h"
#include "cVehiculo.h"

class cPersona
{
	sFecha* fecha_nacimiento;
	cVehiculo* vehiculo;
	cCiudad* ciudad_origen;
	int plata_actual;
	string dni, nya;
public:
	cPersona(sFecha* fn, cVehiculo* vh, cCiudad* co, int pa, string d, string n);
	/*void vendervehiculo(cPersona* cliente);
	string to_string();
	void imprmirdatos();
	void viajar(cCiudad* destino);*/
	~cPersona();
};

