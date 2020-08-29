#include "sCoordenadas.h"

sCoordenadas::sCoordenadas(float la, float lo)
{
	latitud = la;
	longitud = lo;
}

string sCoordenadas::tostring(){

	return  ("-Coordenadas-\n" + 'Latitud:' +to_string(latitud)+"  Longitud:"+to_string(longitud));

}