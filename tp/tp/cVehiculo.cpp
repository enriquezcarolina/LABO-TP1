#include "cVehiculo.h"


cVehiculo::cVehiculo(cCiudad* ua, const int dism, const int cp, const int consumo, int prec, const string m, const string a, const string mo, int capm, string p):
	dist_mantenimiento(dism), capacidad_tanque(cp), consumo(consumo), marca(m), anio_lanzamiento(a), modelo(mo)
{
	if (capm < 0)
		capmaxaire = 30; // si me pasan un parametro invalido la cap maxima de presion en las rudas sera 30
	else capmaxaire = capm;
	cantaire = capm; 
	ubicacion_actual = ua;
	precio = prec;
	nafta_actual = capacidad_tanque;
	dist_recorrida = 0;
	patente = p;
}

cVehiculo::cVehiculo():
dist_mantenimiento(0), capacidad_tanque(0), consumo(0), marca(" "), anio_lanzamiento("2020"), modelo(" "){
	
	capmaxaire=0;
	cantaire=0;
	ubicacion_actual= new cCiudad();
	precio =0;
	nafta_actual =0;
	dist_recorrida=0;
	patente=" ";

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

string cVehiculo::getmodelo()
{
	return modelo;
}

string cVehiculo::getpatente()
{
	return patente;
}

int cVehiculo::getprecio()
{
	return precio;
}

string cVehiculo::getanio()
{
	return anio_lanzamiento;
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
	
	cout << "----- Realizando Mantenimiento---- \n inflando neumaticos y recargando tanque..." << endl;
	
	recargartanque(capacidad_tanque-nafta_actual); //llenar el tanque
	if (cantaire < capmaxaire)
		cantaire = capmaxaire; // vuelvo a inflar los neumaticos 
	return;
}

void cVehiculo::viajar(cCiudad*destino){
	
	float distancia = ubicacion_actual->calculardistancia(destino);
	if( !verificarnaftasuficiente(distancia) ){
		cout<<"Nafta no alcanza para llegar al destino"<<endl;
		return;
	}
	
	else cout<<"-- Viajando de "<<ubicacion_actual->getnombre()<<" a "<<destino->getnombre()<<" --"<<endl;
	for(int i=0; i<=distancia; i=i+10){ 
		
		dist_recorrida++;
		
		if(dist_recorrida%100==0){
			nafta_actual-=consumo;//consumo de nafta cada 100km
			cantaire --; // a medida que el auto viaja se disminuye la presion en sus neumaticos
		}
		if( dist_recorrida%dist_mantenimiento == 0 || cantaire==0){
			//mantenimiento cada dist_mantenimiento o cuando las ruedas se quedan sin aire
			mantenimiento();
		}


	}
	cout<<"Llegando a "<<destino->getnombre()<<endl;
    ubicacion_actual=destino;
	cout<<endl;
	return;
}

int cVehiculo::trazarcamino(cCiudad * destino){

	cCamino*camino=new cCamino(ubicacion_actual, destino);

	return camino->getpeajes();
}

bool cVehiculo::verificarnaftasuficiente(float distancia){
	if(consumo*(distancia/100)<=nafta_actual){
		//la nafta alcanza
		return true;
	}	
	else return false;
}




