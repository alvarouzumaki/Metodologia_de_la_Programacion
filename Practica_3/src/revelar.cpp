#include <iostream>
#include "imagenES.h"
#include "algoritmos.h"

using namespace std;

int main(){
	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int MAXMENSAJE = 10000;
	TipoImagen formato_imagen;
	char nombre_imagen[MAXNOMBRE];
	char mensaje[MAXMENSAJE];
	unsigned char buffer[MAXBUFFER];
	int filas, columnas;
	bool revelar;

	cout << "Introduce el nombre de la imagen: ";
	cin.getline(nombre_imagen, MAXNOMBRE);

	formato_imagen = LeerTipoImagen(nombre_imagen, filas, columnas);

	if(formato_imagen == IMG_PGM){
		LeerImagenPGM (nombre_imagen, filas, columnas, buffer);
	}
	else if(formato_imagen == IMG_PPM){
		LeerImagenPPM (nombre_imagen, filas, columnas, buffer);
	}
	else{
		cout << "Formato no conocido." << endl;
		return 1;
	}

	///////////////////////////////////////////////////////////////////////

	revelar = Revelar(buffer,filas*columnas, mensaje, MAXMENSAJE);
	
	//////////////////////////////////////////////////////////////////////

	if(revelar){
		cout << "Se ha revelado el mensaje." << endl;
		cout << "El mensaje revelado es: " << mensaje << endl;
	}

	else{
		cout << "Se ha producido un error en el revelado." << endl;
		return 1;
	}
}