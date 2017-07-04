#include <iostream>
#include <ctype.h>
#include <istream>
#include "TableroClass.h"
#include "JugadorClass.h"

using namespace std;


int main(){
	Jugador jugador_1, jugador_2;
	int filas, columnas;
	char otra_partida;
	int n;

	cout << "Introduzca numero de filas.";
	do{
		cout << "(Entre 4 y 10):";
		cin >> filas;
	}while(filas < 4 || filas > 10);

	cout << endl;

	cout << "Introduzca numero de columnas. ";
	do{
		cout << "(Entre 4 y 10):";
		cin >> columnas;
	}while(columnas < 4 || columnas > 10);
	
	cout << endl;

	Tablero t(filas,columnas);
	cout << "Inserta el nombre del jugador 1 (NEGRAS): ";
	
	n = 1;
	cin.ignore();
	jugador_1.SetNombre();
	jugador_1.SetNumTurno(n);

	cout << endl;

	cout << "Inserta el nombre del jugador 2 (BLANCAS): ";
	
	n = 2;
	jugador_2.SetNombre();
	jugador_2.SetNumTurno(n);

	cout << endl;

	do{
		n=1;
		t.SetTurno(n);
		t.VaciarTablero();
		

		while(t.FinPartida()){


			if(t.CanSetFicha()){
				
				if(t.GetTurnoActual()==1){
					if(jugador_1.escogePosicion(t)){
						n=0;
						t.SetTurno(n);
					}
				}

				if(t.GetTurnoActual()==2){
					if(jugador_2.escogePosicion(t)){
						n=0;
						t.SetTurno(n);
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

	return -1;

}
