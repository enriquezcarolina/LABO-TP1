#include <iostream>
#include <string>
#include "cCiudad.h"
#include "cPersona.h"
#include "cVehiculo.h"
#include "sCoordenadas.h"
#include "sFecha.h"
using namespace std;

int main()
{

	cCiudad* c = new cCiudad("buenos aires", 3000000, -34.598854, -58.472230);
	cCiudad* c1 = new cCiudad("bahia blanca", 299101, -38.716666666667, -62.26666666667);
	cCiudad* c2 = new cCiudad("rosario", 948312, -32.9575, -60.639444);
	cCiudad* c3 = new cCiudad("baradero", 28537, -33.8, -59.51666666667);
	cCiudad* c4 = new cCiudad("mar del plata", 656456, -38.004848 , -57.548142);
	cVehiculo* v = new cVehiculo(c, 150, 50 ,10, 30000, "fiat", "1998", "uno", 30, "AAB 981");
	cVehiculo* v1 = new cVehiculo(c3, 300, 60, 15, 1000000, "toyota", "2018", "corolla", 33, "AB 123 CD");
	cVehiculo* v2 = new cVehiculo(c4, 200, 45, 12, 100000, "renault", "2020", "kangoo", 30, "DAB 781");
	cVehiculo* v3 = new cVehiculo(*v1);
	cPersona* p1 = new cPersona(v, c, 900000, 30, "ana tolosa", 2, 5, 1978);
	cPersona* p2 = new cPersona(v1, c3, 300000, 30, " juana gonzalez", 22, 2, 1988);
	cPersona* p3 = new cPersona(v2, c1, 1700000, 30, "damian garcia", 5, 9, 1999);
	cPersona* p4 = new cPersona(NULL, c4, 180000, 30, "jose perez", 12, 8, 1986);

	p1->viajar(c3);
    p1->viajar(c2);
    p1->viajar(c);
	p2->viajar(c);
	p2->viajar(c1);
    
	p3->vendervehiculo(p4);
	p3->cambiarvehiculo(v);

	p4->imprmirdatos();
	v1->imprimirpantalla();
	v3->imprimirpantalla();
	
	c = NULL; c1 = NULL; c2 = NULL;c3 = NULL;c4 = NULL; 
	v1 = NULL;v2 = NULL;v = NULL; v3 = NULL;
	p1 = NULL;p2 = NULL;p3 = NULL;p4 = NULL;
	delete c, c1, c2, c3, c4;
	delete v, v1, v2, v3;
	delete p1, p2, p3, p4;
	
	system("pause");
	return 0;
}