#include <iostream>
#include "circulo.h"
#include "punto.h"

using namespace std;

int main(){
	Circulo c;

	cout << "Introduce el radio del circulo: ";
	
	c = LeerCirculo(); 

	cout << "El area del circulo introducido es: " << Area(c) << endl;

}