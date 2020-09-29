parta: main main2
partb: main1b

main: main.c
	gcc -Wall -Werror -ggdb3  main.c -o gensine

main2: main2.c
	gcc -Wall -Werror -ggdb3 main2.c -o gendial

main1b: main1b.c
	gcc -Wall -Werror -ggdb3 main1b.c -o partb

clean:
	rm -f main main2 main1b *~
