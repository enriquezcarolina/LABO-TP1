#include "cPersona.h"

cPersona::cPersona(cVehiculo* vehiculo_personal, cCiudad* ciudad_origen, int plata_actual, int dni, string nombre_apellido, int dia, int mes, int anio)
: ciudad_origen(ciudad_origen), DNI(dni), nya(nombre_apellido) {
	this-> plata_actual=plata_actual;
	vehiculo = vehiculo_personal;
	fecha_nacimiento = new sFecha(dia,mes,anio);
}

cPersona::cPersona()
: ciudad_origen(new cCiudad()), DNI(00000000), nya(" "){
	plata_actual = 0;
	vehiculo = NULL;
	fecha_nacimiento = new sFecha (1,1,2020);
}

void cPersona::vendervehiculo(cPersona* cliente)
{
	if (cliente->getpa() < vehiculo->getprecio())
	{
		cout << "no tiene dinero suficiente para pagar el vehiculo" << endl;
		return;
	}
	else {
		cliente->cambiarvehiculo(vehiculo);// el cliente obtiene su auto nuevo
		cliente->setpa(cliente->getpa() - vehiculo->getprecio()); // el cliente pierde dinero por su compra 
		setpa(plata_actual + vehiculo->getprecio()); // el due�o obtiene el dinero del auto
		vehiculo = NULL;
	}
	return;
}

void cPersona::cambiarvehiculo(cVehiculo* compra)
{
	vehiculo = compra;
	return;

}

cVehiculo* cPersona::getvehiculo()
{
	return vehiculo;
}

int cPersona::getpa()
{
	return plata_actual;
}

void cPersona::setpa(int p)
{
	plata_actual = p;
	return;
}

string cPersona::tostring()
{
	return "nombre: DNI" + to_string(DNI);
}

void cPersona::imprmirdatos()
{
	cout << "nombre: " << nya << endl;
	cout << this->tostring() << "ciudad de origen: " << ciudad_origen->getnombre() << " fecha de nacimiento: " << endl;
	fecha_nacimiento->printfecha();
	cout << "\n auto modelo: " << vehiculo->getmodelo() << " patente: " << vehiculo->getpatente() << " anio de lanzamiento:" << vehiculo->getanio()<< endl;
}

void cPersona::viajar(cCiudad* destino)
{
	if(vehiculo==NULL){
		cout<<"(!) Esta persona no tiene un vehiculo"<<endl;
		return;
	}

	int cantpeajes = vehiculo->trazarcamino(destino);
	if(cantpeajes*50>plata_actual){ //Precio de cada peaje $50
		cout<<"Plata no alcanza para pagar los peajes en el camino"<<endl;
		return;
	}

	else vehiculo->viajar(destino);
}

cPersona::~cPersona()
{
	vehiculo = NULL; 
	fecha_nacimiento = NULL;
	ciudad_origen = NULL;
	delete fecha_nacimiento;
}
