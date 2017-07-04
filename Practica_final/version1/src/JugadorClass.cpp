#include "JugadorClass.h"
#include "TableroClass.h"
#include <ctype.h>
#include <iostream>


	Jugador::Jugador(){
		num_turno = 0;
		puntuacion = 0;
		partidas_ganadas = 0;
	}

	Jugador::Jugador(int& n){
		num_turno = n;
		puntuacion = 0;
		partidas_ganadas = 0;
	}


	void Jugador::TotalScore(const Tablero& t){
		puntuacion += t.GetPuntuacion(num_turno);
	}

	bool Jugador::escogePosicion(Tablero& t){
		int n;
		int aux;
		char c;
		bool termina = false;

		if(NumPosValidas(t) == 1){
			for (int i = 0; i < t.GetFilas(); ++i){
				for (int j = 0; j < t.GetColumnas(); ++j){
					if (t.PosicionValida(i,j)){
						t.SetFicha(i,j);
					}
				}
			}
		}

		else{

			t.prettyPrint();
			
			char d;
			d = (t.GetColumnas() + 'a') - 1;

			do{	
				std::cout << nombre << " escoja un columna (a-" << d << ") " << "y una fila (0-" << t.GetFilas() - 1 << "):";
				std::cin >> c;

				if(c == '!'){
					return true;
				}
				
				std::cin >> n;

				if(std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(1000,'\n');
					std::cout << "Error de formato"<< std::endl;
					n = -1;
				}
				
				c = tolower(c);


				aux = c - 'a';

				
 
				}while(aux > t.GetColumnas() || aux < 0 || n < 0 || n > t.GetFilas() || !t.PosicionValida(n,aux));

			t.SetFicha(n,aux);
			
		}

		return termina;
	}

	void Jugador::SetNombre(){
		std::cin.getline(nombre,50);
	}

	void Jugador::SetNumTurno(int& n){
		num_turno = n;
	}

	void Jugador::MostrarNombreJugador(){
		std::cout << nombre;
	}

	void Jugador::PartidaGanada(){
		partidas_ganadas++;
	}

	int Jugador::NumeroPartidasGanadas(){
		return partidas_ganadas;
	}

	int Jugador::GetPuntuacion(){
		return puntuacion;
	}

	int Jugador::NumPosValidas(Tablero& t){
		int n = 0;

		for(int i = 0; i < t.GetFilas(); i++){
			for(int j = 0; j < t.GetColumnas(); j++){
				if(t.PosicionValida(i,j)){
					n++;
				}
			}
		}

		return n;
	}