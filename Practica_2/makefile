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


all: $(BIN)/distancia_n $(BIN)/delimitar $(BIN)/central $(BIN)/area

#///////////////////////////////////////////////////////////////

$(BIN)/distancia_n : $(OBJ)/distancia_n.o $(LIB)/libformas.a
	$(CXX) -o distancia_n $(OBJ)/distancia_n.o $(LDFLAGS) $(LDLIBS)

$(OBJ)/distancia_n.o : $(SRC)/distancia_n.cpp $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/distancia_n.o $(SRC)/distancia_n.cpp

#///////////////////////////////////////////////////////////////

$(BIN)/delimitar : $(OBJ)/delimitar.o $(LIB)/libformas.a
	$(CXX) -o delimitar $(OBJ)/delimitar.o $(LDFLAGS) $(LDLIBS)


$(OBJ)/delimitar.o : $(SRC)/delimitar.cpp $(INC)/punto.h $(INC)/rectangulo.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/delimitar.o $(SRC)/delimitar.cpp

#///////////////////////////////////////////////////////////////

$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -o central $(OBJ)/central.o $(LDFLAGS) $(LDLIBS)

$(OBJ)/central.o : $(SRC)/central.cpp $(INC)/circulo.h $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp

#///////////////////////////////////////////////////////////////

$(BIN)/area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o area $(OBJ)/area.o $(LDFLAGS) $(LDLIBS)

$(OBJ)/area.o : $(SRC)/area.cpp $(INC)/circulo.h $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp

#///////////////////////////////////////////////////////////////

$(OBJ)/rectangulo.o: $(SRC)/rectangulo.cpp $(INC)/punto.h $(INC)/rectangulo.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/rectangulo.o $(SRC)/rectangulo.cpp

$(OBJ)/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp

$(OBJ)/circulo.o : $(SRC)/circulo.cpp $(INC)/punto.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp

$(LIB)/libformas.a : $(OBJ)/rectangulo.o $(OBJ)/punto.o $(OBJ)/circulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/rectangulo.o $(OBJ)/punto.o $(OBJ)/circulo.o
