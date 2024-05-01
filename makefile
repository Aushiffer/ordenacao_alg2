parametrosCompilacao = -g -Wall #-Wshadow
nomePrograma = trab1grr20232359

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o wrapper.o aux.o
	gcc -o $(nomePrograma) main.o ordenacao.o wrapper.o aux.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

wrapper.o: wrapper.c wrapper.h
	gcc -c wrapper.c $(parametrosCompilacao)

aux.o: aux.c aux.h
	gcc -c aux.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
