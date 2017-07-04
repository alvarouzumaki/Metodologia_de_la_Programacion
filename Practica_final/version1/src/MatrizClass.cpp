#include "MatrizClass.h"

	
	Matriz::Matriz(){
		fils = cols = 0;
	}

	Matriz::Matriz(const int& f, const int& c){
		if(fils > 0 && cols > 0){
			fils = f;
			cols = c;

			for(int i=0; i < fils; i++){
				for(int j=0; j < cols; j++){
					matriz[i][j] = 0;
				}
			}
		}
		else{
			fils = 0;
			cols = 0;
		}
	}

	Matriz::Matriz(const Matriz& otra){
		fils = otra.GetColumnas();
		cols = otra.GetFilas();

		for(int i=0; i < fils; i++){
			for(int j=0; j < cols; j++){
				matriz[i][j] = otra.matriz[i][j];
			}
		}
	}

	int Matriz::GetFilas() const{
		if(fils > 0 && cols > 0){
			return fils;
		}
	}

	void Matriz::SetFilas(const int f){
		fils = f;
	}


	int Matriz::GetColumnas() const{
		if(fils > 0 && cols > 0){
			return cols;
		}
	}

	void Matriz::SetColumnas(const int c){
		cols = c;
	}

	int Matriz::GetPosicion(const int& i, const int& j)const{
		if(fils > 0 && cols > 0){
			return matriz[i][j];
		}
	}

	void Matriz::SetPosicion(const int& i, const int& j, const int& n){
		if(fils > 0 && cols > 0){
			matriz[i][j] = n;
		}
	}