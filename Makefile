all: main

main: main.c sorted-list.c
	gcc -c sorted-list.c
	ar rvs libsl.a sorted-list.o
	gcc -Wall -Werror -o sl main.c libsl.a

clean:
	rm -f sl
	rm -f libsl.a
	rm -f sorted-list.o
