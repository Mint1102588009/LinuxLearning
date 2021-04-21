target=test
INC=./include
SRC=$(wildcard ./src/*.c)
OBJ=./*.o

$(target):$(OBJ)
	gcc $(OBJ) -o $(target) -Wall

$(OBJ):$(SRC)
	gcc -I $(INC) -c $(SRC)
