#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_

#include <iostream>
#include "punto.h"

using namespace std;


struct Rectangulo{
	Punto sup_dcha;
	Punto inf_izq;
};

void Avanzar(istream& is);
void InicializarRectangulo(Rectangulo& r, const Punto& p1, const Punto& p2);
void BoundingBox(Rectangulo& r, istream& is);
Punto InferiorIzquierda(const Rectangulo& r);
Punto SuperiorDerecha(const Rectangulo& r);
double Area(const Rectangulo& r);
bool Escribir(ostream& os, Rectangulo& r);
#endif