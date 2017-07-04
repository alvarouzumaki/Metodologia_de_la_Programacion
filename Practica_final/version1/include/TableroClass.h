#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "MatrizClass.h"

class Tablero{
	private:
		Matriz tablero;
		int turno;

		void CambiarTurno();

		char IntaChar(int n);

	public:
		Tablero();

		Tablero(int& f, int& c);

		//////////////////////////////////////////////

		int GetFilas() const;

		int GetColumnas() const;

		int GetPosicion(const int& i, const int& j) const;

		int GetTurnoActual() const;

		bool FinPartida() const;

		int Ganador() const;

		int GetPuntuacion(const int& n) const;

		bool PosicionValida(const int& i, const int& j) const;

		bool CanSetFicha();

		void SetFicha(const int& f, const int& c);

		void VaciarTablero();

		void prettyPrint();

		void InicializarTablero();

		void SetTurno(int& n);

};



#endif