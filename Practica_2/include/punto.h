#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>
using namespace std;

struct Punto {
    double x,y;
};

Punto LeerPunto();
void EscribirPunto (Punto p);
void InicializarPunto (Punto& p, double cx, double cy);
double GetX (Punto p);
double GetY (Punto p);
double Distancia (Punto p1, Punto p2);
Punto PuntoMedio (Punto p1, Punto p2);
bool Leer(istream& is, Punto& p);
bool Escribir(ostream& os,const Punto& p);
#endif