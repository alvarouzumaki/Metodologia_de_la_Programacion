/**
  * @file matriz_bit.cpp
  * @brief Fichero de definiciones para insertar la implementación deseada
  *
  * Incluye la definición correspondiente dependiendo de la selección en matriz_bit.h
  * 
  * @warning Este fichero no se debe modificar
  *
  */

#include "matriz_bit.h" // Aquí se define el valor de CUAL_COMPILO

#if CUAL_COMPILO==1
  #include "matriz_bit1.cpp"
#elif CUAL_COMPILO==2
  #include "matriz_bit2.cpp"
#elif CUAL_COMPILO==3
  #include "matriz_bit3.cpp"
#else
  #include "matriz_bit4.cpp"
#endif
