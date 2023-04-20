all: add_nbo

add-nbo: add-nbo.o
	g++ -o add_nbo add_nbo.o

add-nbo.o: add_nbo.cpp
	g++ -c -o add_nbo.o add_nbo.cpp

clean:
	rm -f *.o
	rm -f add-nbo.o
