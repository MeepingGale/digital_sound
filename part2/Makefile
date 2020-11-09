all: parta

parta: main

main.o: main.cpp 
	g++ -c main.cpp
	
main: main.o
	g++ -o main main.o -lm




clean:
	rm -f main *.o
