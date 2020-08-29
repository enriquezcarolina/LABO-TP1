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

string cVehiculo::tostring(){

	return ("Ubicacion Actual: "+ ubicacion_actual->tostring( )+"\nDistancia recorrida: "+to_string(dist_recorrida)+"\nCapacidad del tanque"+to_string(capacidad_tanque)+"\nConsumo: "+to_string(consumo)+"\nPrecio: "+to_string(precio)+"\nModelo: "+modelo+"\nMarca: "+marca+"\nAnio de lanzamiento: "+anio_lanzamiento);

}

void cVehiculo::imprimirpantalla(){
	cout<<this->tostring();
	return;
}

bool cVehiculo::recargartanque(int cantnafta){
	
	if(cantnafta<0 || cantnafta>(capacidad_tanque-nafta_actual)) {
		//si es un numero negativo o la cantidad haria que supere la capacidad
		cout<<"//Cantidad invalida//"<<endl;
		return false;
	}
	else nafta_actual+=cantnafta;
	return true;
}

void cVehiculo::mantenimiento(){

	recargartanque(capacidad_tanque-nafta_actual); //llenar el tanque
	//no se que mas podria ir en el mantenimiento

	return;
}

void cVehiculo::viajar(cCiudad*destino){
	
	float distancia = ubicacion_actual->calculardistancia(destino);
	if( !verificarnaftasuficiente(distancia) ){
		cout<<"Nafta no alcanza para llegar al destino"<<endl;
		return;
	}
	
	else for(int i=0; i<=distancia; i=i+50){ 
		//no sabia bien como hacer la parte que va viajando y se suma la distancia recorrida
		dist_recorrida+=50;
		
		if( dist_recorrida%dist_mantenimiento == 0 ){
			//mantenimiento cada dist_mantenimiento
			mantenimiento();
		}

	}

	return;
}

bool cVehiculo::verificarnaftasuficiente(float distancia){
	if(consumo*(distancia/100)<=nafta_actual){
		//la nafta alcanza
		return true;
	}	
	else return false;
}




