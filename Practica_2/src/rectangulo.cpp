#include <iostream>
#include <fstream>
#include "rectangulo.h"
#include "punto.h"
#include <cmath>

using namespace std;

void Avanzar(istream& is){
	while(isspace(is.peek()) || is.peek()=='#'){
		if(is.peek()=='#')
			is.ignore(1024,'\n');
		else is.ignore();
	}
}

void InicializarRectangulo(Rectangulo& r, const Punto& p1, const Punto& p2){
	r.sup_dcha = p1;
	r.inf_izq = p2;
}

void BoundingBox(Rectangulo& r, istream& is){
	Punto p, min, max;
	int i = 0;
	bool exito;

	Avanzar(is);
	while(!is.eof()){

		exito = Leer(is,p);
		
		if(exito == true){
			if(i==0){
				InicializarPunto(min,p.x,p.y);
				InicializarPunto(max,p.x,p.y);	
			}
			
			if(min.x > p.x && min.y > p.y){
				min.x = p.x;
				min.y = p.y;
			}

			if(max.x < p.x || max.y < p.y){
				if(max.x < p.x){
					max.x = p.x;
				}
				else
					max.y = p.y;
			}
		}

		Avanzar(is);
		i++;

	}

	InicializarRectangulo(r, max, min);

}

Punto InferiorIzquierda(const Rectangulo& r){
	return r.inf_izq;
}

Punto SuperiorDerecha(const Rectangulo& r){
	return r.sup_dcha;
}

double Area(const Rectangulo& r){
	Punto p, q, k;

	q = InferiorIzquierda(r);
	k = SuperiorDerecha(r);

	InicializarPunto(p,k.x,q.y); 

	double base, altura;

	base = Distancia(p,q);
	altura = Distancia(p,k);

	return base * altura;

}

bool Escribir(ostream& os, Rectangulo& r){
	Escribir(cout, r.inf_izq);
	os << "-";
	Escribir(cout, r.sup_dcha);

	return os.good();
}