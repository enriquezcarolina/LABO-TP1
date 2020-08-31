#include "cPersona.h"

cPersona::cPersona(cVehiculo* vh, cCiudad* co, int pa, int d, string n, int dia, int m, int a)
: ciudad_origen(co), DNI(d), nya(n) {
	plata_actual=pa;
	vehiculo = vh;
	fecha_nacimiento = new sFecha(d,m,a);
}

cPersona::cPersona()
: ciudad_origen(new cCiudad()), DNI(00000000), nya(" "){
	plata_actual=0;
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
	int cantpeajes = vehiculo->trazarcamino(destino);
	if(cantpeajes*50>plata_actual){ //Precio de cada peaje $50
		cout<<"Plata no alcanza para pagar los peajes en el camino"<<endl;
		return;
	}

	else vehiculo->viajar(destino);
}

cPersona::~cPersona()
{
	delete vehiculo;
	delete fecha_nacimiento;
	delete ciudad_origen;
}
