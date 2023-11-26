all: remover archivos ejecutable
remocer:
	rm -f *.o
archivos: main.c funciones.c
	gcc -c main.c
	gcc -c funciones.c
ejecutable: main.o Funciones.o
	gcc -o exe main.o Funciones.o