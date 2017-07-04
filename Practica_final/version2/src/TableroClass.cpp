#include <iostream>
#include <cstring>
#include <istream>
#include <fstream>
#include "TableroClass.h"

	void Tablero::CambiarTurno(){
			if(turno == 1){
				turno = 2;
			}
			else{
				turno = 1;
			}

			if(!CanSetFicha()){
				if(turno == 1){
					turno = 2;
				}
			
				else{
					turno = 1;
				}

				if(!CanSetFicha()){
					turno = 0;
				}
			}

	}

	
	char Tablero::IntaChar(int n){
		if(n == 0){
			return ' ';
		}

		if(n == 1){
			return 'x';
		}

		if(n == 2){
			return 'o';
		}

		return ' ';
	}

	void Tablero::Avanzar(std::istream& is){
		while(isspace(is.peek()) || is.peek()=='%'){
			if(is.peek()=='%')
				is.ignore(1024,'\n');
			else is.ignore();
		}
	}

	//////////////////////////////////////////////////////////////////////////////

	Tablero::Tablero():turno(1),ayuda(false),jugador_comienzo(2),fichas_restantes(1),fichas_maximas(1){}

	Tablero::Tablero(int f, int c): tablero(f,c){
		turno = 1;
		jugador_comienzo = 2;
		ayuda =  false;
		fichas_restantes = 1;
		fichas_maximas = 1; 

		VaciarTablero();
	}

	/////////////////////////////////////////////////////////////////////////////

	Tablero& Tablero::operator=(const Tablero& t){
		if(this != &t){
			tablero = t.tablero;
			turno = t.turno;
			jugador_comienzo = t.jugador_comienzo;
		}

		return *this;
	}

	int Tablero::GetFilas() const{
		return tablero.GetFilas();
	}

	int Tablero::GetColumnas() const{
		return tablero.GetColumnas();
	}

	int Tablero::GetPosicion(const int& i, const int& j) const{
		if(i < 0 || j < 0 || i > GetFilas() || j > GetColumnas()){
			return -1;
		}
		return tablero.GetPosicion(i,j);
	}

	int Tablero::GetTurnoActual() const{
		return turno;
	}

	bool Tablero::FinPartida() const{
		if(turno == 0){
			return false;
		}

		return true;

	}

	int Tablero::Ganador() const{
		int cont1, cont2;
		int res;

		cont1 = cont2 = 0;

		for(int i = 0; i < tablero.GetFilas(); i++){
			for(int j = 0; j < tablero.GetColumnas(); j++){
				if(tablero.GetPosicion(i,j) == 1){
					cont1++;
				}

				if(tablero.GetPosicion(i,j) == 2){
					cont2++;
				}
			}
		}

		if(cont1 == cont2){
			res = 0;
		}else if(cont1 > cont2){
			res = 1;
		}
		else{
			res = 2;
		}

		return res;
	}

	int Tablero::GetPuntuacion(const int& n) const{
		int puntuacion = 0;

		if(n==1){
			for(int i = 0; i < tablero.GetFilas(); i++){
				for(int j = 0; j < tablero.GetColumnas(); j++){
					if(tablero.GetPosicion(i,j) == 1){
						puntuacion++;
					}
				}
			}
		}

		if(n==2){
			for(int i = 0; i < tablero.GetFilas(); i++){
				for(int j = 0; j < tablero.GetColumnas(); j++){
					if(tablero.GetPosicion(i,j) == 2){
						puntuacion++;
					}
				}
			}
		}

		return puntuacion;

		}

	
	bool Tablero::PosicionValida(const int& x, const int& y) const{
		int otra = 1;
		int iterador = 1;
		
		if(turno == 1){
			otra = 2;
		}

		if(GetPosicion(x,y) == 0){

			
			if(GetPosicion(x-1,y) == otra){
				while(GetPosicion(x-iterador,y) == otra && GetPosicion(x-iterador,y) != -1){
					iterador++;
					if(GetPosicion(x-iterador,y) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x+1,y) == otra){
				while(GetPosicion(x+iterador,y) == otra && GetPosicion(x+iterador,y) != -1){
					iterador++;
					if(GetPosicion(x+iterador,y) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x,y-1) == otra){
				while(GetPosicion(x,y-iterador) == otra && GetPosicion(x,y-iterador) != -1){
					iterador++;
					if(GetPosicion(x,y-iterador) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x,y+1) == otra){
				while(GetPosicion(x,y+iterador) == otra && GetPosicion(x,y+iterador) != -1){
					iterador++;
					if(GetPosicion(x,y+iterador) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x+1,y+1) == otra){
				while(GetPosicion(x+iterador,y+iterador) == otra && GetPosicion(x+iterador,y+iterador) != -1){
					iterador++;
					if(GetPosicion(x+iterador,y+iterador) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x+1,y-1) == otra){
				while(GetPosicion(x+iterador,y-iterador) == otra && GetPosicion(x+iterador,y-iterador) != -1){
					iterador++;
					if(GetPosicion(x+iterador,y-iterador) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x-1,y-1) == otra){
				while(GetPosicion(x-iterador,y-iterador) == otra && GetPosicion(x-iterador,y-iterador) != -1){
					iterador++;
					if(GetPosicion(x-iterador,y-iterador) == turno){
						return true;
					}
				}
			}

			
			iterador = 1;
			if(GetPosicion(x-1,y+1) == otra){
				while(GetPosicion(x-iterador,y+iterador) == otra && GetPosicion(x-iterador,y+iterador) != -1){
					iterador++;
					if(GetPosicion(x-iterador,y+iterador) == turno){
						return true;
					}
				}
			}
		}

		return false;
	}

	bool Tablero::CanSetFicha(){
		for(int i = 0; i < GetFilas(); i++){
			for(int j = 0; j < GetColumnas(); j++){
				if(PosicionValida(i,j)){
					return true;
				}
			}
		}
		return false;
	}

	void Tablero::SetFicha(const int& x, const int& y){
		if(PosicionValida(x,y)){
			int otra = 1;
			int iterador = 1;

			if(turno == 1){
				otra = 2;
			}
			
			if(GetPosicion(x,y) == 0){

				if(GetPosicion(x-1,y) == otra){
					while(GetPosicion(x-iterador,y) == otra){
						iterador++;
					}
					if(GetPosicion(x-iterador,y) == turno){
	
						for(int i = x - iterador; i <= x; i++){
							tablero.SetPosicion(i,y,turno);
						}
					}
				}

				iterador = 1;

				if(GetPosicion(x+1,y) == otra){
					while(GetPosicion(x+iterador,y) == otra){
						iterador++;
					}
					if(GetPosicion(x+iterador,y) == turno){
						for(int i = x + iterador; i >= x; i--){
							tablero.SetPosicion(i,y,turno);
						}
					}
				}
				
				iterador = 1;

				if(GetPosicion(x,y-1) == otra){
					while(GetPosicion(x,y-iterador) == otra){
						iterador++;
					}
					if(GetPosicion(x,y-iterador) == turno){
						for(int i = y - iterador; i <= y; i++){
							tablero.SetPosicion(x,i,turno);
						}
					}
				}

				iterador = 1;

				if(GetPosicion(x,y+1) == otra){
					while(GetPosicion(x,y+iterador) == otra){
						iterador++;
					}
					if(GetPosicion(x,y+iterador) == turno){
						for(int i = y + iterador; i >= y; i--){
							tablero.SetPosicion(x,i,turno);
						}
					}
				}

				iterador = 1;

				if(GetPosicion(x+1,y+1) == otra){
					while(GetPosicion(x+iterador,y+iterador) == otra){
						iterador++;
					}
					if(GetPosicion(x+iterador,y+iterador) == turno){
						for(int it = 0; it <= iterador; it++)
							tablero.SetPosicion(x+it,y+it,turno);
					}
				}
				

				iterador = 1;

				if(GetPosicion(x+1,y-1) == otra){
					while(GetPosicion(x+iterador,y-iterador) == otra && GetPosicion(x+iterador,y-iterador) != -1){
						iterador++;
					}
					if(GetPosicion(x+iterador,y-iterador) == turno){
						for(int it = 0; it <= iterador; it++)
							tablero.SetPosicion(x+it,y-it,turno);	
					}
				}

				iterador = 1;

				if(GetPosicion(x-1,y-1) == otra){
					while(GetPosicion(x-iterador,y-iterador) == otra && GetPosicion(x-iterador,y-iterador) != -1){
						iterador++;
					}
					if(GetPosicion(x-iterador,y-iterador) == turno){
						for(int it = 0; it <= iterador; it++)
							tablero.SetPosicion(x-it,y-it,turno);	
					}
				}	
				

				iterador = 1;

				if(GetPosicion(x-1,y+1) == otra){
					while(GetPosicion(x-iterador,y+iterador) == otra && GetPosicion(x-iterador,y+iterador) != -1){
						iterador++;
					}
					if(GetPosicion(x-iterador,y+iterador) == turno){
						for(int it = 0; it <= iterador; it++)
							tablero.SetPosicion(x-it,y+it,turno);			
					}
				}
			}
		}

		if(fichas_restantes > 1 && CanSetFicha()){
			fichas_restantes--;
		}
		else{
			fichas_restantes = fichas_maximas;
			CambiarTurno();
		}

	}


	void Tablero::VaciarTablero(){
		tablero = tablero_original;

		if(jugador_comienzo == 1){
			jugador_comienzo = 2;
			SetTurno(jugador_comienzo);
		}
		else{
			jugador_comienzo = 1;
			SetTurno(jugador_comienzo);
		}
	}


	void Tablero::prettyPrint(std::ostream& os){
		char c = 'a';

		os << "  ";

		for(int i = 0; i < tablero.GetFilas();  i++){
			os << "\033[1;34m" << c << "\033[1;0m" << " ";
			c++;
		}

		os << std::endl;

		os << " ";

		for(int i = 0; i < tablero.GetFilas(); i++){
			os << "--" ;
		}

		os << std::endl;

		for(int i = 0; i < tablero.GetFilas(); i++){
			os << "\033[1;34m" << i << "\033[1;0m" << "|";
			for(int j = 0; j < tablero.GetFilas(); j++){
				if(PosicionValida(i,j) && !ayuda){
					os  << IntaChar(tablero.GetPosicion(i,j));
				}
				if(PosicionValida(i,j) && ayuda == true){
					os << "\033[1;95m" << "·" << "\033[1;0m";
				}

				if(tablero.GetPosicion(i,j) == 1){
					os << "\033[1;93m" << IntaChar(tablero.GetPosicion(i,j)) << "\033[1;0m";
				}

				if(tablero.GetPosicion(i,j) == 2){
					os << "\033[1;32m" << IntaChar(tablero.GetPosicion(i,j)) << "\033[1;0m";
				}

				if(tablero.GetPosicion(i,j) == 0 && !PosicionValida(i,j)){
					os  << IntaChar(tablero.GetPosicion(i,j));
				}

				os << "|";
			}
			os << std::endl;
		}

		os << " ";

		for(int i = 0; i < tablero.GetFilas(); i++){
			os << "--" ;
		}

		os << std::endl;

		if(turno == 1 || turno == 2){
			os << "Turno  " << (fichas_maximas - fichas_restantes + 1) << "/" << fichas_maximas << " del jugador " << GetTurnoActual() << ": " << " (" << IntaChar(GetTurnoActual()) << ")" << std::endl;
		}
		else{
			os << "Partida finalizada." ;
		}
	}

	void Tablero::InicializarTablero(){
		tablero.SetPosicion((GetFilas()/2)-1,(GetColumnas()/2)-1,1);
		tablero.SetPosicion((GetFilas()/2)-1,(GetColumnas()/2),2);
		tablero.SetPosicion((GetFilas()/2),(GetColumnas()/2)-1,2);
		tablero.SetPosicion((GetFilas()/2),(GetColumnas()/2),1);
	}

	void Tablero::SetTurno(int& n){
		turno = n;
	}

	void Tablero::SetAyuda(bool n){
		ayuda = n;
	}

	bool Tablero::cargarTablero(){
		char nombre_partida[200];

		std::cout << "Introduzca nombre de archivo: ";
		std::cin.getline(nombre_partida,200);

		bool exito;
		std::ifstream fichero;
		char linea[200];

		fichero.open(nombre_partida);

	
		if(fichero.fail()){
			std::cerr << "No se puede leer " << nombre_partida;
			exito = false;
		}
		else{
			fichero.getline(linea,200);

			if(strcmp(linea,"#MP-TABLERO-REVERSI-1.0")==0){
				
				Avanzar(fichero);

				fichero >> tablero;

				tablero_original = tablero;

				Avanzar(fichero);

				fichero >> turno;

				Avanzar(fichero);

				fichero >> fichas_restantes;

				Avanzar(fichero);

				fichero >> fichas_maximas;

				exito = !fichero.fail();
			}	
			else{
				std::cerr << "El archivo " << nombre_partida << " no parece de formato reversi."; 
				exito = false;
			}	
		}

		return exito;

	}
	

	std::ostream& operator<<(std::ostream& os, Tablero& t){
		os << t.tablero;
		os << t.tablero_original;
		os << t.turno << std::endl;
		os << t.fichas_restantes << std::endl;
		os << t.fichas_maximas;

		return os;
	}

	std::istream& operator>>(std::istream& is, Tablero& t){
		is >> t.tablero;
		is >> t.tablero_original;
		is >> t.turno;
		is >> t.fichas_restantes;
		is >> t.fichas_maximas;

		return is;
	}
