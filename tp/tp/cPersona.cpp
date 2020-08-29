#include "cPersona.h"

cPersona::cPersona(sFecha* fn, cVehiculo* vh, cCiudad* co, int pa, string d, string n)
{
	
	fecha_nacimiento = fn;
	vehiculo = vh;
	ciudad_origen = co;
	dni = d;
	nya = n;

	

}

cPersona::~cPersona()
{
	delete vehiculo;
	delete fecha_nacimiento;
	delete ciudad_origen;
}
