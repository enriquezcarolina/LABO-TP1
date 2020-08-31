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
	string  nya;
	int DNI;
public:
	cPersona(cVehiculo* vh, cCiudad* co, int pa, int d, string n, int dia, int m, int a);
	void vendervehiculo(cPersona* cliente);
	void cambiarvehiculo(cVehiculo* compra);
	cVehiculo* getvehiculo();
	int getpa();
	void setpa(int p);

	string to_string();
	void imprmirdatos();
	void viajar(cCiudad* destino);
	~cPersona();
};

