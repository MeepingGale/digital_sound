all: main main2

main: main.c
	gcc -Wall -Werror -ggdb3  main.c -o gensine

main2: main2.c
	gcc -Wall -Werror -ggdb3 main2.c -o gendial

clean:
	rm -f main main2 *~
