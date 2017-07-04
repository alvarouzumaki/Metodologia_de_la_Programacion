#ifndef _MATRIZ_OPER__H_
#define _MATRIZ_OPER__H_

#include "matriz_bit.h"
#include <iosfwd>

using namespace std;

bool Leer(istream &is, MatrizBit &m);
bool Escribir(ostream &os, const MatrizBit &m);
bool Leer(const char nombre[], MatrizBit &m);
bool Escribir(const char nombre[], const MatrizBit &m);
void And(MatrizBit &res, const MatrizBit &m1, const MatrizBit &m2);
void Or(MatrizBit &res, const MatrizBit &m1, const MatrizBit &m2);
void Not(MatrizBit &res, const MatrizBit &m);
void Traspuesta(MatrizBit &res, const MatrizBit &m);

#endif