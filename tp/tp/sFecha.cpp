#include "sFecha.h"

sFecha::sFecha(int d, int m, int a)
{
	dia = d;
	mes = m;
	anio = a;
}

sFecha::~sFecha()
{
}

void sFecha::printfecha()
{
	cout << dia << "/" << mes << "/" << anio << endl;
	return;
}
