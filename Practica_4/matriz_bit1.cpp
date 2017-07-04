#include <cassert> 
#include "matriz_bit1.h"

bool Inicializar(MatrizBit& m, int fils, int cols){
	bool exito = false;

	if(fils <= 10 && cols <= 10){
		m.fils = fils;
		m.cols = cols;

		for(int i = 0; i < fils; i++){
			for(int j = 0; j < cols; j++){
				m.m[i][j]=false;
			}
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
	assert(f <= m.f && c <= m.c);
	return m.m[f][c];
}

void Set(MatrizBit& m, int f, int c, bool v){
	assert(f <= m.f && c <= m.c);
	m.m[f][c] = v;
}