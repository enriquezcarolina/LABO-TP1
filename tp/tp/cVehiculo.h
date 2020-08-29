#pragma once 
#include <iostream>
#include <string>
using namespace std;
class cCiudad;
class cVehiculo
{
	cCiudad* ubicacion_actual;
	int dist_recorrida;
	const int dist_mantenimiento;
	const int capacidad_tanque;
	const int consumo;
	int precio;
	const string modelo, marca, anio_lanzamiento;
	int nafta_actual;
public: 
	cVehiculo(cCiudad* ua, const int dism, const int cp, const int consumo,int prec, const string m, const string a, const string mo);
	/*bool recargartanque(int cantnafta);
	string tostring();
	void imprimirpantalla();
	void viajar(cCiudad* destino);
	void mantenimiento();
	bool verificarnaftasuficiente(cCiudad* destino);*/

	
	~cVehiculo();

};

