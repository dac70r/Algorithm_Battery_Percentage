all: battery main
	gcc main.o battery.o

battery: battery
	gcc -c battery.c

main: main
	gcc -c main.c

clean: main
	rm main.o