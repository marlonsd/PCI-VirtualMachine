maquina: main.o machine.o 
	gcc main.o machine.o -o maquina

main.o: main.c machine.h
	gcc -c main.c

machine.o: machine.c machine.h
	gcc -c machine.c
