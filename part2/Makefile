all: parta

parta: main


main: main.o
	g++ -o main main.o -lm

main.o: main.cpp 
	g++ -c main.cpp


clean:
	rm -f main *.o
