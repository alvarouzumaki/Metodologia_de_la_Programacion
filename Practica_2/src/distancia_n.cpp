#include <iostream>
#include <fstream>
#include "punto.h"

using namespace std;

int main(int argc, char* argv[]){
	Punto p,aux;
	bool exito, fin_entrada;
	double distancia = 0;
	int i = 0;

	if(argc == 1){
		while(!cin.eof()){
			exito = Leer(cin, p);
			
			if(i > 0 && exito == true){
				distancia += Distancia(p,aux);
			}
			
			aux = p;
			
		 	i++;
		}
		fin_entrada = cin.eof();
	}
	else{
		ifstream f(argv[1]);
		if(!f){
			cerr << "Error no se abre " << argv[1] << endl;
			return 1;
		}

		while(!cin.eof()){
			exito = Leer(cin, p);
			
			if(i > 0 && exito == true){
				distancia += Distancia(p,aux);
			}
			
			aux = p;
			
		 	i++;
		}
	}

	if(!fin_entrada){
		cerr << "Error inesperado. No se ha leido toda la entrada" << endl;
		return 1;		
	}

	cout << "La distancia es: " << distancia << endl;

}