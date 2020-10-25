all: parta partb

parta: main main2

partb: main1b


main: main.o gensnd.o
	gcc -o gensine main.o gensnd.o

main.o: main.c gensnd.h
	gcc -c main.c

main2: main2.o gensnd.o
	gcc -o gendial main2.o gensnd.o

main2.o: main2.c gensnd.h
	gcc -c main2.c

main1b: main1b.o gensnd.o iosnd.o
	gcc -o dtmf main1b.o gensnd.o iosnd.o

main1b.o: gensnd.h main1b.c
	gcc -c main1b.c

gensnd.o: gensnd.h gensnd.c iosnd.h iosnd.c
	gcc -c gensnd.c iosnd.c

iosnd.o: iosnd.h iosnd.c
	gcc -c iosnd.c

clean:
	rm -f gensine gendial dtmf *.o
