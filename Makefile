all: main gensnd

main: main.c
	gcc -Wall -Werror -ggdb3  main.c -o main

gensnd: gensnd.c
	gcc -Wall -Werror -ggdb3 gensnd.c -o gensnd

clean:
	rm -f main gensnd *~
