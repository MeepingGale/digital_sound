all: main main2

main: main.c
	gcc -Wall -Werror -ggdb3  main.c -o main

main2: main2.c
	gcc -Wall -Werror -ggdb3 main2.c -o main2

clean:
	rm -f main main2 *~
