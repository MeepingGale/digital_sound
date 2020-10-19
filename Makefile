parta: main main2
partb: main1b
all: main main2 main1b

main: gensnd.h gensnd.c
	gcc main.c -o gensine

main2: gensnd.h gensnd.c
	gcc main2.c -o gendial

main1b.o: gensnd.h gensnd.c
	gcc main1b.c -o dtmf

clean:
	rm -f main main2 main1b *~
