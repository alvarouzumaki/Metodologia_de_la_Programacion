#include <iostream>
#include <cmath>
#include "punto.h"

using namespace std;

Punto LeerPunto()
{
	Punto a_devolver;
	char c;

	cin >> c >> a_devolver.x >> c >> a_devolver.y >> c;

	return a_devolver; 
}

void EscribirPunto (Punto p)
{
	cout << "( " << p.x << "," << p.y << ")" << endl;
}

void InicializarPunto (Punto& p, double cx, double cy)
{
	p.x = cx;
	p.y = cy;
}

double GetX (Punto p)
{
	return p.x;
}

double GetY (Punto p)
{
	return p.y;
}

double Distancia (Punto p1, Punto p2)
{
	return sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
}

Punto PuntoMedio (Punto p1, Punto p2)
{
	Punto media;

	media.x = (p1.x + p2.x)/2;
	media.y = (p1.y + p2.y)/2;

	return media;
}

bool Leer(istream& is, Punto& p){
	char c;

	is >> c;

	if(c != '(')
		return false;

	is >> p.x;
	is >> c;

	if(c != ',')
		return false;

	is >> p.y;
	is >> c;

	if(c != ')')
		return false;
	
	return true;
}

bool Escribir(ostream& os,const Punto& p){
	os << "(" << p.x << "," << p.y << ")";
	return true;
}