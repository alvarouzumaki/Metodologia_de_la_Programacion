#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <iostream>

const int MAX=10;

class Matriz{
	private:
		int* datos;
		int fils, cols;

	public:
		Matriz();

		Matriz(const int& f, const int& c);

		Matriz(const Matriz& otra);

		~Matriz();

		Matriz& operator=(const Matriz& m);

		int GetFilas() const;
		
		int GetColumnas() const;

		int GetPosicion(const int& i, const int& j) const;

		void SetPosicion(int i,int j, int n);
};

std::istream& operator>>(std::istream& is, Matriz& m);

std::ostream& operator<<(std::ostream& os, const Matriz& m);

#endif