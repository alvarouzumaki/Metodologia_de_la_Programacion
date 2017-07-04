#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "TableroClass.h"

class Jugador{
	private:
		char nombre[50];
		int num_turno;
		int puntuacion;
		int partidas_ganadas;

		
	public:
		Jugador();
		Jugador(int& n);

		////////////////////////////////////////////////////////////////////////////////////

		void TotalScore(const Tablero& t);
		bool escogePosicion(Tablero& t);
		void SetNombre();
		void SetNumTurno(int& n);
		const char* ConsultaNombre();
		void MostrarNombreJugador();
		void PartidaGanada();
		int NumeroPartidasGanadas();
		int GetPuntuacion();
		int NumPosValidas(Tablero& t);
};





#endif