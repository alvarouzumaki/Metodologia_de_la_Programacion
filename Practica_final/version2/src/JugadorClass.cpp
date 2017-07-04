#include "JugadorClass.h"
#include "TableroClass.h"
#include <ctype.h>
#include <iostream>
#include <cstddef>
#include <cstdlib>


	Jugador::Jugador(){
		num_turno = 0;
		puntuacion = 0;
		partidas_ganadas = 0;
		num_comodin = 0;
		nombre = NULL;
	}

	Jugador::Jugador(int n){
		num_turno = n;
		num_comodin = 0;
		puntuacion = 0;
		partidas_ganadas = 0;
		nombre = NULL;
	}

	Jugador::Jugador(const Jugador& j){

		SetNombre(j.nombre);

		num_turno = j.num_turno;
		puntuacion = j.puntuacion;
		partidas_ganadas = j.partidas_ganadas;
		num_comodin = j.num_comodin;
	}

	Jugador::~Jugador(){
		delete [] nombre;
	}

	Jugador& Jugador::operator=(Jugador& j){
		if(this != &j){
			SetNombre(j.nombre);
			num_turno = j.num_turno;
			puntuacion = j.puntuacion;
			partidas_ganadas = j.partidas_ganadas;
			num_comodin = j.num_comodin;
		}

		return *this;
	}

	void Jugador::TotalScore(const Tablero& t){
		puntuacion += t.GetPuntuacion(num_turno);
	}

	bool Jugador::escogePosicion(Tablero& t){
		int n;
		int aux;
		char c;
		bool termina = false;
		Posicion v[100];

		if(JugadorAutomatico()){
			int pos;
			pos = PosicionesValidasStruct(t, v);
			
			pos = rand() % pos;

			std::cout << "*************************** " << nombre << " ***************************" << std::endl;

			t.prettyPrint();
			
			t.SetFicha(v[pos].fila, v[pos].columna);

			std::cout << "El jugador AUTOMATICO " << nombre << " va a escoger ficha..." << std::endl;
			std::cout << std::endl;
		}
		else{

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
							
					if(c == '?'){

						if(num_comodin > 0){

							num_comodin--;

							bool ayuda = true;

							t.SetAyuda(ayuda);

							t.prettyPrint();

							ayuda = false;

							t.SetAyuda(ayuda);

							if(num_comodin == 0){
								std::cout << nombre << ", este es tu ultimo comodin, ";
							}
							
							if(num_comodin > 0){
								if(num_comodin == 1){
									std::cout << nombre << " te queda " << num_comodin << " comodin, ";
								}
								else{
									std::cout << nombre << " te quedan " << num_comodin << " comodines, ";
								}
							}
						}
						
						else{
							std::cout << "No te quedan comodines. ";
						}
							
						std::cout << "escoja una columna (a-" << d << ") " << "y una fila (0-" << t.GetFilas() - 1 << "):";
						std::cin >> c;

						if(c == '!'){
							return true;
						}
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
			}

			t.SetFicha(n,aux);
		}

		return termina;
	}

	void Jugador::SetNombre(char c[]){
		int longitud;

		delete [] nombre;

		longitud = LongitudNombre(c);

		nombre = new char[longitud + 1];

		for(int i = 0; i < longitud; i++){
			nombre[i] = c[i];
		}

		nombre[longitud] = '\0';
	}

	void Jugador::SetNumTurno(int n){
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

	int Jugador::PosicionesValidasStruct(Tablero& t, Posicion v[]){
		int n = 0;

		for(int i = 0; i < t.GetFilas(); i++){
			for(int j = 0; j < t.GetColumnas(); j++){
				if(t.PosicionValida(i,j)){
					v[n].fila = i;
					v[n].columna = j;
					n++;
				}
			}
		}

		return n;
	}

	int Jugador::LongitudNombre(char c[]){
		int longitud = 0;

		for(int i = 0; c[i] != '\0'; i++){
			longitud++;
		}

		return longitud;
	}

	void Jugador::SetNumeroComodines(int n){
		num_comodin = n;
	}

	bool Jugador::JugadorAutomatico(){
		if(nombre[0] == '@'){
			return true;
		}

		return false;
	}

	std::istream& operator>>(std::istream& is, Jugador& j){

		while(isspace(is.peek())) {
			is.ignore();
		}
		if (is.peek()!='!'){
        	is.setstate(std::ios::failbit);
        }

		char nom[200];
		int nturn,punt,part_ganadas, n_comodin;

		is.ignore();

		is.getline(nom,200); 
		is >> nturn >> punt >> part_ganadas >> n_comodin;


        if (nturn<1 || nturn>2){
        	is.setstate(std::ios::failbit);
        }

        if (is){
			j.SetNombre(nom);
			j.num_turno = nturn ;
			j.puntuacion = punt;
			j.partidas_ganadas = part_ganadas;
			j.num_comodin = n_comodin;
 		}

		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Jugador& j){
		os << '!' <<j.nombre << std::endl;
		os << j.num_turno << " " << j.puntuacion << " " << j.partidas_ganadas << " " << j.num_comodin << std::endl;

		return os;
	}