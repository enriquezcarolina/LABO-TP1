#include "cCiudad.h"
#include "sCoordenadas.h"

#define R_tierra 6371 //km

cCiudad::cCiudad(string nom, int pob, float lo, float la)
: nombre(nom){
    coordenadas = new sCoordenadas(lo, la);
    poblacion_total = pob;
}

cCiudad::cCiudad()
: nombre(" ") {
   
    coordenadas = new sCoordenadas();
    poblacion_total=0;

}

cCiudad::~cCiudad()
{
    coordenadas = NULL;
	delete coordenadas;

}

string cCiudad::tostring(){

return ("Ciudad : "+nombre+"\nPoblacion: "+to_string(poblacion_total)+coordenadas->tostring());

}

float cCiudad::calculardistancia(cCiudad* destino){
	
	float lat1, lat2, long1, long2;
	float a=0, c=0, dif_long=0, dif_lat=0;
   
    lat1=coordenadas->getLatitud();
    lat2=destino->coordenadas->getLatitud();
    long1=coordenadas->getLongitud();
    long2=destino->coordenadas->getLongitud();
    
    
    dif_long = (long2-long1)*M_PI/180;
    dif_lat = (lat2-lat1)*M_PI/180;
    
    lat1=(lat1)*M_PI/180;
    lat2=(lat2)*M_PI/180;
    long1=(long1)*M_PI/180;
    long2=(long2)*M_PI/180;
    
	a = pow(sin(dif_lat/2),2) + cos(coordenadas->getLatitud()) * cos(destino->coordenadas->getLatitud()) * pow(sin(dif_long/2),2);

	c = 2*atan2(sqrt(a),sqrt(1-a) );

	return R_tierra * c;

}


