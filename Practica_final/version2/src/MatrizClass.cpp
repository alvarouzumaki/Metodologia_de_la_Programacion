#include "MatrizClass.h"
#include <cassert>
#include <cstddef>
#include <iostream>
	
	Matriz::Matriz(){
		fils = cols = 0;
		datos = NULL;
	}

	Matriz::Matriz(const int& f, const int& c){
		fils = f;
		cols = c;

		datos = new int[fils*cols];

		for(int i=0; i < fils; i++){
			for(int j=0; j < cols; j++){
				datos[i*cols+j] = 0;
			}
		}
	}

	Matriz::Matriz(const Matriz& otra){
		fils = otra.fils;
		cols = otra.cols;

		datos = new int[fils*cols];
			
		for(int i = 0; i < fils; i++){
			for(int j = 0; j < cols; j++){
				datos[i*cols+j] = otra.datos[i*cols+j];
			}
		}
	}

	Matriz::~Matriz(){
		delete [] datos;
	}

	Matriz& Matriz::operator=(const Matriz& m){
		if(this != &m){
			delete [] datos;
			
			cols = m.cols;
			fils = m.fils;
			
			datos = new int[fils*cols];

			for(int i = 0; i < fils; i++){
				for(int j = 0; j < cols; j++){
					datos[i*cols+j] = m.datos[i*cols+j];
				}
			}

		}

		return *this;

	}

	int Matriz::GetFilas() const{
		assert(fils >= 0 && cols >= 0);
		return fils;
	}


	int Matriz::GetColumnas() const{
		assert(fils >= 0 && cols >= 0);
		return cols;
	}

	int Matriz::GetPosicion(const int& i, const int& j)const{
		assert(i >= 0 && j >= 0);
		return datos[i*cols+j];
	}

	void Matriz::SetPosicion(int i, int j, int n){
		assert(i >= 0 && j >= 0);
		datos[i*cols+j] = n;
	}

	std::istream& operator>>(std::istream& is, Matriz& m){
		int fils, cols,n;

		is >> fils;
		is >> cols;

        if (!is || fils < 0 || cols< 0) {
        	is.setstate(std::ios::failbit);
        	return is;
        }


		Matriz aux(fils,cols);


		for(int i = 0; i < fils; i++){
			for(int j = 0; j < cols; j++){
				is >> n;
				aux.SetPosicion(i,j,n);
			}
		}

		if(!is.fail()){
			m = aux;
		}

		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Matriz& m){
		os << m.GetFilas() << " " << m.GetColumnas() << std::endl;

		for (int i = 0; i < m.GetFilas(); i++){
			for (int j = 0; j < m.GetColumnas(); j++){
				os << m.GetPosicion(i,j) << ' ';
			}
			os << std::endl;
		}

		return os;
	}