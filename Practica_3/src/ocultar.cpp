#include <iostream>
#include "imagenES.h"
#include "algoritmos.h"

using namespace std;

int main(){
	const int MAXBUFFER = 1000000;
	const int MAXNOMBRE = 100;
	const int MAXMENSAJE = 10000;
	char nombre_imagen[MAXNOMBRE];
	char nombre_salida[MAXNOMBRE];
	char mensaje[MAXMENSAJE];
	unsigned char buffer[MAXBUFFER];
	int columnas, filas;
	TipoImagen formato_imagen;
	bool ocultar;

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

	////////////////////////////////////////////////////////////////////////

	cout << "Introduce el mensaje a ocultar: ";
	cin.getline(mensaje,MAXMENSAJE);

	ocultar = Ocultar(mensaje, buffer);

	////////////////////////////////////////////////////////////////////////////
	if(ocultar){
		cout << "Introduce el nombre de la imagen codificada: ";
		cin.getline(nombre_salida, MAXNOMBRE);

		if(formato_imagen == IMG_PGM){
			EscribirImagenPGM (nombre_salida, buffer, filas, columnas);
		}
		else if(formato_imagen == IMG_PPM){
			EscribirImagenPPM (nombre_salida, buffer, filas, columnas);
		}
		else{
			cout << "Formato no conocido." << endl;
			return 1;
		}
	}

	else{
		cout << "Error en la ocultacion." << endl;
		return 1;
	}
}