#include "cPersona.h"

cPersona::cPersona(cVehiculo* vh, cCiudad* co, int pa, int d, string n, int dia, int m, int a)
{
	
	fecha_nacimiento = new sFecha(d, m, a);
	vehiculo = vh;
	ciudad_origen = co;
	DNI = d;
	nya = n;

	

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
		setpa(plata_actual + vehiculo->getprecio()); // el dueño obtiene el dinero del auto
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

string cPersona::to_string()
{
	return "nombre: DNI" + to_string(DNI); // no se pq no anda
}

void cPersona::imprmirdatos()
{
	cout << "nombre: " << nya << endl;
	cout << this->to_string() << "ciudad de origen: " << ciudad_origen << " fecha de nacimiento: " << endl;
	fecha_nacimiento->printfecha();
	cout << "\n auto modelo: " << vehiculo->getmodelo() << " patente: " << vehiculo->getpatente() << " anio de lanzamiento:" << vehiculo->getanio()<< endl;
}

void cPersona::viajar(cCiudad* destino)
{
	vehiculo->viajar(destino);
}

cPersona::~cPersona()
{
	delete vehiculo;
	delete fecha_nacimiento;
	delete ciudad_origen;
}
