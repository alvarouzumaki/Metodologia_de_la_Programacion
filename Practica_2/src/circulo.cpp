#include <iostream>
#include <cmath>
#include "circulo.h"

using namespace std;

Circulo LeerCirculo()
{
	Circulo c;
	char l;

	cin >> c.radio >> l; 
	c.centro = LeerPunto();

	return c;
}
void EscribirCirculo(Circulo c)
{
	cout << c.radio << "-";
	EscribirPunto(c.centro);
}
void InicializarCirculo (Circulo& c, Punto centro, double radio)
{
	c.centro = centro;
	c.radio = radio;
}
Punto Centro (Circulo c)
{
	return c.centro;
}
double Radio (Circulo c)
{
	return c.radio;
}
double Area (Circulo c)
{
	return (M_PI * pow(c.radio,2));
}
bool Interior (Punto p, Circulo c)
{
	return (c.radio < Distancia(c.centro, p));
}
double Distancia (Circulo c1, Circulo c2)
{
	return Distancia(c1.centro, c2.centro);
}
