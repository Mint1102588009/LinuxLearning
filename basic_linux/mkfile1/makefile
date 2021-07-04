target=mint
src=./src/*.cpp
#src=$(wildcard ./src/*.cpp)
obj=./*.o
inc=./include/

$(target):$(obj)
	g++ -o $(target) $(obj)
%.o:$(src)
	g++ -I $(inc) -c $^
clean:
	-rm *.o
	-rm $(target)
	echo "clean"
