AR= ar
CXX= g++
CXXFLAGS= -Wall -g -I ./include
LDFLAGS= -L ./lib
LDLIBS= -lformas
OBJ=obj
LIB=lib
SRC=src
INC=include
BIN=bin


all: $(BIN)/revelar $(BIN)/ocultar

#///////////////////////////////////////////////////////////////

$(BIN)/revelar : $(OBJ)/revelar.o $(OBJ)/algoritmos.o $(OBJ)/imagenES.o
	$(CXX) -o revelar $(OBJ)/revelar.o $(OBJ)/algoritmos.o $(OBJ)/imagenES.o

$(OBJ)/revelar.o : $(SRC)/revelar.cpp $(INC)/algoritmos.h $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/revelar.o $(SRC)/revelar.cpp

#///////////////////////////////////////////////////////////////

$(BIN)/ocultar : $(OBJ)/ocultar.o $(OBJ)/algoritmos.o $(OBJ)/imagenES.o
	$(CXX) -o ocultar $(OBJ)/ocultar.o $(OBJ)/algoritmos.o $(OBJ)/imagenES.o


$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp $(INC)/algoritmos.h $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/ocultar.o $(SRC)/ocultar.cpp

#///////////////////////////////////////////////////////////////

$(OBJ)/algoritmos.o : $(SRC)/algoritmos.cpp $(INC)/algoritmos.h $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/algoritmos.o $(SRC)/algoritmos.cpp

#///////////////////////////////////////////////////////////////

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp


clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a