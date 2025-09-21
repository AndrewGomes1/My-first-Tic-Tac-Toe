# -*- Makeflile -*-

ticTacToe: main.o
	gcc -o ticTacToe main.o

main.o: main.c
	gcc -c main.c 

clean:
	rm *.o ticTacToe
