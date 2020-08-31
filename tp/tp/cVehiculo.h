#pragma once 
#include <iostream>
#include <string>
#include "math.h"
#include "cCiudad.h"
#include "cCamino.h"
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
	int cantaire; // presion actual de las ruedas, se expresa en libra por pulgada cuadrada
	int capmaxaire; // capacidad maxima de presion para las ruedas 
    string  patente;
public: 
	cVehiculo(cCiudad* ua, const int dism, const int cp, const int consumo,int prec, const string m, const string a, const string mo, int capm, string p);
	cVehiculo();
	bool recargartanque(int cantnafta);
	void viajar(cCiudad* destino); //sumar dist_recorrida
	void mantenimiento(); //mantenimiento cada dist_mantenimiento
	bool verificarnaftasuficiente(float distancia); //verificar que la nafta alcanza para realizar el viaje
	int trazarcamino(cCiudad* destino);//devuelve la cantidad de peajes

	string tostring();
	void imprimirpantalla();
	string getmodelo();
	string getpatente();
	int getprecio();
	string getanio();
	
	~cVehiculo();

};

