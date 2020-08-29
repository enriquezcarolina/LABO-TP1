#include "cVehiculo.h"

cVehiculo::cVehiculo(cCiudad* ua, const int dism, const int cp, const int consumo, int prec, const string m, const string a, const string mo):
	dist_mantenimiento(dism), capacidad_tanque(cp), consumo(consumo), marca(m), anio_lanzamiento(a), modelo(mo)
{
	ubicacion_actual = ua;
	precio = prec;
	nafta_actual = 0;
	dist_recorrida = 0;
}

cVehiculo::~cVehiculo()
{
	delete ubicacion_actual;
}
