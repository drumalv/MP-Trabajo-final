# Definición de macros para definir las carpetas de trabajo
BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
# Opciones de compilación
# -Wall muestra todas las advertencias
# -g compila en modo "depuración"
OPT=-Wall -g 
# Nombre de la práctica
PRJ=practica6

# Las macros se usan en las reglas del makefile como si fuesen variables
# que se sustituyen por su valor definido anteriormente

all: $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen $(BIN)/testMorphing

$(BIN)/testarteASCII : $(LIB)/libimagen.a $(OBJ)/byte.o $(OBJ)/testarteASCII.o
	g++ -o $@ $(OBJ)/byte.o $(OBJ)/testarteASCII.o -limagen -L$(LIB)
	
$(OBJ)/byte.o : $(SRC)/byte.cpp $(INC)/byte.h 
	g++ $(OPT) -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INC) 
	
$(LIB)/libimagen.a : $(OBJ)/imagen.o $(OBJ)/pgm.o 
	ar -rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/byte.h $(INC)/pgm.h
	g++ $(OPT) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC) 
	
$(OBJ)/lista.o : $(SRC)/lista.cpp $(INC)/lista.h $(INC)/imagen.h $(INC)/byte.h $(INC)/pgm.h
	g++ $(OPT) -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -I$(INC) 

$(OBJ)/pgm.o : $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ $(OPT) -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)

$(OBJ)/testarteASCII.o : $(INC)/imagen.h $(SRC)/testarteASCII.cpp
	g++ $(OPT) -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -I$(INC)

$(BIN)/testplano : $(LIB)/libimagen.a $(OBJ)/byte.o $(OBJ)/testplano.o
	g++ -o $@ $(OBJ)/byte.o $(OBJ)/testplano.o -limagen -L$(LIB)

$(OBJ)/testplano.o : $(INC)/imagen.h $(SRC)/testplano.cpp
	g++ $(OPT) -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -I$(INC)
	
$(BIN)/testMorphing : $(LIB)/libimagen.a $(OBJ)/byte.o $(OBJ)/lista.o $(OBJ)/testMorphing.o
	g++ -o $@ $(OBJ)/byte.o $(OBJ)/lista.o $(OBJ)/testMorphing.o -limagen -L$(LIB)

$(OBJ)/testMorphing.o : $(INC)/pgm.h $(INC)/imagen.h $(INC)/lista.h $(INC)/byte.h $(SRC)/testMorphing.cpp
	g++ $(OPT) -c $(SRC)/testMorphing.cpp -o $(OBJ)/testMorphing.o -I$(INC)

$(BIN)/testimagen : $(LIB)/libimagen.a $(OBJ)/byte.o $(OBJ)/testimagen.o
	g++ -o $@ $(OBJ)/byte.o $(OBJ)/testimagen.o -limagen -L$(LIB)

$(OBJ)/testimagen.o : $(INC)/imagen.h $(SRC)/testimagen.cpp
	g++ $(OPT) -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -I$(INC)

clean: 
	rm -f $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/*
	
zip: clean
	zip -r $(ZIP)/$(PRJ).zip *

