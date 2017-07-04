CXX= g++
CXXFLAGS= -Wall -g -I ./include 

OBJ=obj
LIB=lib
SRC=src
INC=include
BIN=bin



$(BIN)/reversi : $(OBJ)/MatrizClass.o $(OBJ)/TableroClass.o $(OBJ)/JugadorClass.o $(OBJ)/reversi.o
	$(CXX) -g -o $(BIN)/reversi $(OBJ)/reversi.o $(OBJ)/MatrizClass.o $(OBJ)/TableroClass.o $(OBJ)/JugadorClass.o

$(OBJ)/reversi.o : $(SRC)/reversi.cpp $(INC)/TableroClass.h $(INC)/JugadorClass.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/reversi.o $(SRC)/reversi.cpp

$(OBJ)/MatrizClass.o : $(SRC)/MatrizClass.cpp $(INC)/MatrizClass.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/MatrizClass.o $(SRC)/MatrizClass.cpp

$(OBJ)/TableroClass.o : $(SRC)/TableroClass.cpp $(INC)/TableroClass.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/TableroClass.o $(SRC)/TableroClass.cpp

$(OBJ)/JugadorClass.o : $(SRC)/JugadorClass.cpp $(INC)/JugadorClass.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/JugadorClass.o $(SRC)/JugadorClass.cpp 




clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o $(BIN)/*