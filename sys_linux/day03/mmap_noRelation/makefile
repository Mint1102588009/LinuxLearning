target1=test1
target2=test2
INC=./include
src=./src/*.c
obj1=test1.o
obj2=test2.o

app:$(obj1) $(obj2)
	gcc $(obj1) -o $(target1) -Wall
	gcc $(obj2) -o $(target2) -Wall

%.o:$(src)
	gcc -I $(INC) -c $(src) 

.PHONY:Debug clean
Debug:$(obj1) $(obj2)
	gcc $(obj1) -o $(target1) -Wall -g
	gcc $(obj2) -o $(target2) -Wall -g

clean:
	-rm *.o
	-rm $(target1) $(target2)
