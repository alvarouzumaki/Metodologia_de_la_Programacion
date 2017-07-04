#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

bool Ocultar(const char mensaje[], unsigned char buffer[]);

bool Revelar(const unsigned char buffer[], const int num_pixeles, char mensaje[], const int longitud_mensaje);

#endif