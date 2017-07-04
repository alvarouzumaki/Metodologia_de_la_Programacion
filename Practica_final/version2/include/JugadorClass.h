#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "TableroClass.h"

struct Posicion{
	char columna;
	int fila;
};


class Jugador{
	private:
		char* nombre;
		int num_turno;
		int puntuacion;
		int partidas_ganadas;
		int num_comodin;
		
		
	public:
		Jugador();

		Jugador(int n);

		Jugador(const Jugador& j);

		~Jugador();

		////////////////////////////////////////////////////////////////////////////////////

		Jugador& operator=(Jugador& j);

		void TotalScore(const Tablero& t);

		bool escogePosicion(Tablero& t);

		void SetNombre(char c[]);

		void SetNumTurno(int n);

		const char* ConsultaNombre();

		void MostrarNombreJugador();

		void PartidaGanada();

		int NumeroPartidasGanadas();

		int GetPuntuacion();

		int NumPosValidas(Tablero& t);

		int PosicionesValidasStruct(Tablero& t, Posicion v[]);

		int LongitudNombre(char c[]);

		void SetNumeroComodines(int n);

		bool JugadorAutomatico();

		friend std::istream& operator>>(std::istream& is, Jugador& j);

		friend std::ostream& operator<<(std::ostream& os, const Jugador& j);
};



#endif