all: main

main: main.c
	gcc -с src/*.c
	gcc -o output.o public/*.o
	./output.o