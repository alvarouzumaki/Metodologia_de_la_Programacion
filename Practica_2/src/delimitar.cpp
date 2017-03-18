#include <iostream>
#include <fstream>
#include "rectangulo.h"

using namespace std;

int main(int argc, char* argv[]){
	Rectangulo r;
	bool fin_entrada;
	bool exito;

	if(argc==1){  //Solo hemos ejecutado el programa sin pasarle nada por parametros
		BoundingBox(r,cin);
		fin_entrada = cin.eof();
	}
	else{
		ifstream f(argv[1]); //Le pasa el nombre del archivo parametro 1
		if(!f){
			cerr << "Error: no se abre " << argv[1] << endl;
			return 1;
		}

		BoundingBox(r,f);
		fin_entrada = f.eof();
	}

	if(!fin_entrada){
		cerr << "Error inesperado. No se ha leido toda la entrada" << endl;
		return 1;
	}

	cout << "El rectangulo que comprende todos los puntos es: ";
	Escribir(cout, r);
	cout << endl;
}