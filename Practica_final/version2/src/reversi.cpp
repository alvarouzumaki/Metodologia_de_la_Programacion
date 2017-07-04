#include <iostream>
#include <cctype>
#include <istream>
#include <cstring>
#include "TableroClass.h"
#include "JugadorClass.h"
#include <fstream>

using namespace std;

bool Guardar(char* c, Jugador& j1, Jugador& j2, Tablero& t){
	ofstream fichero;
	bool exito = false;

	strcat(c, ".otelo");

	fichero.open(c);

	if(fichero.is_open()){
		fichero << "#MP-SUPER-REVERSI-1.0" << endl;
		fichero << j1 << endl;
		fichero << j2 << endl;
		fichero << t << endl;

		exito = true;
	}

	return exito;
}

bool DialogoGuardar(Jugador& j1, Jugador& j2, Tablero& t){
	char c;
	bool guardar = false;

	do{
		cout << "¿Deseas guardar la partida?(S/N): ";
		cin >> c;

		c = tolower(c);
	}while(c != 's' && c != 'n');
		
	cin.ignore();

	cout << endl;

	if(c == 's'){
		char nombre_partida[200];

		cout << "Introduzca el nombre del archivo: ";
		cin.getline(nombre_partida,200);

		cout << endl;
		
		guardar = Guardar(nombre_partida, j1, j2, t);

		if(guardar){
			cout << "Guardado con éxito" << endl;
			cout << endl;
		}
	}

	return guardar;
}

bool Cargar(char nombre[], Jugador& j1, Jugador& j2, Tablero& t){
	bool exito;
	ifstream fichero;
	char linea[200];

	fichero.open(nombre);

	if(fichero.fail()){
		cerr << "No se puede leer " << nombre;
		exito = false;
	}
	else{
		fichero.getline(linea,200);

		if(strcmp(linea,"#MP-SUPER-REVERSI-1.0")==0){
			fichero >> j1;
			fichero >> j2;	
			fichero >> t;

			exito = !fichero.fail();
		}
		else{
			cerr << "El archivo " << nombre << " no parece de formato reversi."; 
			exito = false;
		}	
	}

	return exito;
}

bool DialogoCargar(Jugador& j1, Jugador& j2, Tablero& t){
	bool cargar;
	char nombre_partida[200];

	cout << "Introduzca nombre de archivo: ";
	cin.getline(nombre_partida,200);
	cargar = Cargar(nombre_partida,j1,j2,t);

	return cargar;
}

bool Reversi(Jugador& jugador_1, Jugador& jugador_2, Tablero& t){
	char otra_partida;

	do{

		while(t.FinPartida()){


			if(t.CanSetFicha()){
				
				if(t.GetTurnoActual()==1){
					if(jugador_1.escogePosicion(t)){
						DialogoGuardar(jugador_1,jugador_2,t);
					}
				}

				if(t.GetTurnoActual()==2){
					if(jugador_2.escogePosicion(t)){
						DialogoGuardar(jugador_1,jugador_2,t);
					}
				}
			}
		}
		
		t.prettyPrint();

		if(t.Ganador() == 1){																		
			jugador_1.PartidaGanada();
			cout << "Ganador jugador " << t.Ganador() << "." << endl;   
		}else if(t.Ganador() == 2){
			jugador_2.PartidaGanada();
			cout << "Ganador jugador " << t.Ganador() << "." << endl;
		}
		else{
			cout << "Ha habido un empate." << endl;
		}

		jugador_1.TotalScore(t);	
		jugador_2.TotalScore(t);			


		cout << "Resultados tras esta partida: " << endl;

		cout << "\t-";
		jugador_1.MostrarNombreJugador();
		cout << " lleva " << jugador_1.NumeroPartidasGanadas() << " partidas ganadas, acumulando un total de: " << jugador_1.GetPuntuacion() << endl;
		cout << "\t-";
		jugador_2.MostrarNombreJugador();
		cout << " lleva " << jugador_2.NumeroPartidasGanadas() << " partidas ganadas, acumulando un total de: " << jugador_2.GetPuntuacion() << endl;
		cout << "¿Jugar de nuevo(S/N)?: ";

		do{
			cin >> otra_partida;
			otra_partida = tolower(otra_partida);
		}while(otra_partida != 's' && otra_partida != 'n');

		if(otra_partida == 's'){
			t.VaciarTablero();
		}

	}while(otra_partida == 's');

	cout << "Resultados finales: " << endl;
	cout << " ";
	jugador_1.MostrarNombreJugador();
	cout << " " << jugador_1.NumeroPartidasGanadas() << " partidas ganadas, acumulando un total de: " << jugador_1.GetPuntuacion() << endl;
	cout << " ";
	jugador_2.MostrarNombreJugador();
	cout << " " << jugador_2.NumeroPartidasGanadas() << " partidas ganadas, acumulando un total de: " << jugador_2.GetPuntuacion() << endl;
	cout << endl;
	cout << "El juego ha finalizado." << endl;

	return 1;
}

int main(int argc, char* argv[]){
	if(argc == 2){
		Jugador j1, j2;
		Tablero t2;
		if(DialogoCargar(j1,j2,t2)){
			Reversi(j1,j2,t2);		
		}
		else{
			cerr << "No se ha cargado la partida." << endl;
		}

	}else if(argc == 1){
		Jugador jugador_1, jugador_2;
		int n, comodines;
		Tablero t;
		
		if(t.cargarTablero() == false){
			cout << endl;
			return -1;
		}

		cout << endl;

		cout << "Introduzca el numero de comodines: ";
		do{
			cin >> comodines;
		}while(comodines < 0);
		jugador_1.SetNumeroComodines(comodines);
		jugador_2.SetNumeroComodines(comodines);
		cout << endl;

		cout << "Inserta el nombre del jugador 1 (NEGRAS): ";
		
		char linea[100];

		n = 1;
		cin.ignore();
		cin.getline(linea,100);
		jugador_1.SetNombre(linea);
		jugador_1.SetNumTurno(n);

		
		cout << endl;

		cout << "Inserta el nombre del jugador 2 (BLANCAS): ";
		
		char linea_2[100];

		n = 2;
		cin.getline(linea_2,100);
		jugador_2.SetNombre(linea_2);
		jugador_2.SetNumTurno(n);

		cout << endl;

		Reversi(jugador_1,jugador_2,t);
	}
	else{
		cerr << "Se ha podrucido un error, el numero de argumentos no es correcto";
		return 1;
	}
}

	
