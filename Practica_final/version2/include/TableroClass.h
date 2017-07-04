#ifndef _TABLERO_H_
#define _TABLERO_H_

#include <iostream>
#include "MatrizClass.h"

class Tablero{
	private:
		Matriz tablero,tablero_original;
		int turno;
		bool ayuda;
		int jugador_comienzo;
		int fichas_restantes;
		int fichas_maximas;


		void CambiarTurno();

		char IntaChar(int n);

		void Avanzar(std::istream& is);

	public:
		Tablero();

		Tablero(int f, int c);

		Tablero& operator=(const Tablero& t);

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

		void prettyPrint(std::ostream& os = std::cout);

		void InicializarTablero();

		void SetTurno(int& n);

		void SetAyuda(bool n);

		bool cargarTablero();

		friend std::ostream& operator<<(std::ostream& os, Tablero& t);
		
		friend std::istream& operator>>(std::istream& is, Tablero& t);
};




#endif