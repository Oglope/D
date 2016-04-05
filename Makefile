all:
	gcc bin_sem.c -c
	gcc init_pack.c -c
	gcc 1.c -c
	gcc 2.c -c
	gcc init_pack.o bin_sem.o -lpthread -o init_pack
	gcc 1.o bin_sem.o -lpthread -o 1
	gcc 2.o bin_sem.o -lpthread -o 2
	gcc Makefifo.c -lpthread -o Makefifo
