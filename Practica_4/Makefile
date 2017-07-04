# Con un código tan simple, usemos un makefile simplificado
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++03 -pedantic -g

# ************ Generación de ejecutable ************

calcular: matriz_bit.h matriz_bit.cpp matriz_operaciones.h matriz_operaciones.cpp matriz_bit1.h matriz_bit1.cpp matriz_bit2.h matriz_bit2.cpp  matriz_bit3.h matriz_bit3.cpp matriz_bit4.h matriz_bit4.cpp calcular.cpp
	$(CXX) $(CXXFLAGS) -o calcular matriz_bit.cpp matriz_operaciones.cpp calcular.cpp

# ************ Limpieza ************
clean :
	-rm calcular ./*~ ./*.o
