#include <iostream>
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
}
	//////////////////////////////////////////////////////////////////////////////

	Tablero::Tablero():turno(1){}

	Tablero::Tablero(int& f, int& c){
		tablero.SetFilas(f);
		tablero.SetColumnas(c);
		turno = 1;
	}

	/////////////////////////////////////////////////////////////////////////////

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
						//ARREGLO for(,i<=,)
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

		CambiarTurno();

	}


	void Tablero::VaciarTablero(){
		for(int i = 0; i < tablero.GetFilas(); i++){
			for(int j = 0; j < tablero.GetColumnas(); j++){
				tablero.SetPosicion(i,j,0);
			}
		}

		InicializarTablero();
	}


	void Tablero::prettyPrint(){
		char c = 'a';

		std::cout << "  ";

		for(int i = 0; i < tablero.GetFilas();  i++){
			std::cout << "\033[1;34m" << c << "\033[1;0m" << " ";
			c++;
		}

		std::cout << std::endl;

		std::cout << " ";

		for(int i = 0; i < tablero.GetFilas(); i++){
			std::cout << "--" ;
		}

		std::cout << std::endl;

		for(int i = 0; i < tablero.GetFilas(); i++){
			std::cout << "\033[1;34m" << i << "\033[1;0m" << "|";
			for(int j = 0; j < tablero.GetFilas(); j++){
				if(PosicionValida(i,j)){
					std::cout << "\033[1;95m" << "·" << "\033[1;0m";
				}

				if(tablero.GetPosicion(i,j) == 1){
					std::cout << "\033[1;93m" << IntaChar(tablero.GetPosicion(i,j)) << "\033[1;0m";
				}

				if(tablero.GetPosicion(i,j) == 2){
					std::cout << "\033[1;32m" << IntaChar(tablero.GetPosicion(i,j)) << "\033[1;0m";
				}

				if(tablero.GetPosicion(i,j) == 0 && !PosicionValida(i,j)){
					std::cout  << IntaChar(tablero.GetPosicion(i,j));
				}

				std::cout << "|";
			}
			std::cout << std::endl;
		}

		std::cout << " ";

		for(int i = 0; i < tablero.GetFilas(); i++){
			std::cout << "--" ;
		}

		std::cout << std::endl;

		if(turno == 1 || turno == 2){
			std::cout << "Turno del jugador " << GetTurnoActual() << ": " << " (" << IntaChar(GetTurnoActual()) << ")" << std::endl;
		}
		else{
			std::cout << "Partida finalizada." ;
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