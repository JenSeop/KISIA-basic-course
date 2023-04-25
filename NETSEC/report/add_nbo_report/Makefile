# Makefile
# add_nbo

all : add_nbo

add_nbo : add-nbo.o
	g++ -o add_nbo add_nbo.o

add-nbo.o : add_nbo.cpp
	g++ -c -o add_nbo.o add_nbo.cpp

clean:
	rm -f *.o
	rm -r add_nbo
	rm -f add-nbo.o
