#include "sCoordenadas.h"

sCoordenadas::sCoordenadas(float la, float lo)
{
	latitud = la;
	longitud = lo;
}

sCoordenadas::sCoordenadas(){

	latitud=0;
	longitud=0;

}

string sCoordenadas::tostring(){

	return  ("-Coordenadas-\n" + 'Latitud:' +to_string(latitud)+"  Longitud:"+to_string(longitud));

}