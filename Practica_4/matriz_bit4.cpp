#include "matriz_bit4.h"

bool Inicializar(MatrizBit &m, int fils, int cols) {
  bool exito = false;

  if (fils * cols <= 32 * m.fil_col && fils >= 0 && cols >= 0) {
    m.fil_col = (fils << 8) | cols;

    if (fils*cols >= 32) {
      for (int i = 0; i < (fils*cols) / 32; i++) {
        m.m[i] = 0;
      }
    }

    int aux = m.m[(fils*cols) / 32];

    for (int i = 0; i < 8; ++i) {
      aux = aux & ~(1 << i);
    }

    m.m[(fils*cols) / 32] = aux;

    exito = true;
  }

  return exito;
}

int Filas(const MatrizBit &m) { 
  return m.fil_col >> 8; 
}

int Columnas(const MatrizBit &m) { 
  return m.fil_col && 0xFF; 
}

bool Get(const MatrizBit &m, int f, int c) {
  const int POSICION = f * Columnas(m) + c;

  return (1 << POSICION % 32) & m.m[POSICION / 32];
}

void Set(MatrizBit &m, int f, int c, bool v) {

  if (f < Filas(m) && c < Columnas(m) && f >= 0 && c >= 0) {
    const int POSICION = f * Columnas(m) + c;
    const int POSICION_VECTOR = POSICION / 32;
    const int POSICION_BIT = POSICION % 32;
    unsigned int aux = 1 << POSICION_BIT;

    if (v) {
      m.m[POSCION_VECTOR] = aux;
    } 
    else {
      m.m[POSICION_VECTOR] = m.m[POSICION_VECTOR] & ~aux;
    }
  }
}