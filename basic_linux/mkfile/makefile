SRC = $(wildcard ./src/*.cpp)
OBJ = $()
INC = ./include
target = $(app)

$(target):$(OBJ)
	g++ $(OBJ) -o $(target)

%.o:%.cpp
	g++ -I $(INC) -c $^
