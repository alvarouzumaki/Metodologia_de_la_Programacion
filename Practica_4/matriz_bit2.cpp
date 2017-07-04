#include <cassert> 
#include "matriz_bit2.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
	bool exito = false 

	if(fils*cols <= 100){
		m.fils = fils;
		m.cols = cols;

		for(int i = 0; i < fils*cols; i++){
				m.m[i]=false;
		}

		exito = true;
	}
	else
		return exito;
}

int Filas (const MatrizBit& m){
	return m.fils;
}

int Columnas( const MatrizBit& m){
	return m.cols;
}

bool Get(const MatrizBit& m, int f, int c){
	assert(f*c <= 100);
	return m.m[m.fils*m.cols + m.cols];
}

void Set(MatrizBit& m, int f, int c, bool v){
	assert(f*c <= 100);
	m.m[m.fils*m.cols + m.cols] = v;
};