#ifndef _MATRIZ_H_
#define _MATRIZ_H_

const int MAX=10;

class Matriz{
	private:
		int matriz[MAX][MAX];
		int fils, cols;

	public:
		Matriz();

		Matriz(const int& f, const int& c);

		Matriz(const Matriz& otra);

		int GetFilas() const;

		void SetFilas(const int f);
		
		int GetColumnas() const;

		void SetColumnas(const int c);

		int GetPosicion(const int& i, const int& j) const;

		void SetPosicion(const int& i, const int& j, const int& n);
};



#endif