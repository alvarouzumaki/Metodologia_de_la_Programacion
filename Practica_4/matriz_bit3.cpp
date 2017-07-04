
#include "matriz_bit3.h"
#include <cassert> 

bool Inicializar(MatrizBit &m, int fils, int cols) {
  bool exito = false;

  if ((fils * cols) <= 100 && fils >= 0 && cols >= 0) {
    m.fil_col = (fils << 16) | cols;

    for (int i = 0; i < (fils * cols); i++) {
      m.m[i] = '0';
    }

    exito = true;

  }

  return exito;
}

int Filas(const MatrizBit &m) { 
  return m.fil_col >> 16;
}

int Columnas(const MatrizBit &m) { 
  return m.fil_col & 0xFFFF; 
}

bool Get(const MatrizBit &m, int f, int c) {
  assert(f*c <= 100);
  return m.m[Columnas(m) * f + c] == '1';
}

void Set(MatrizBit &m, int f, int c, bool v) {
  assert(f*c <= 100 && f >= 0 && c >= 0);
  m.m[Columnas(m) * f + c] = v ? '1' : '0';
  
}