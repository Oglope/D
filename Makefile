all:
	gcc bin_sem.c -c
	gcc init_pack.c -c
	gcc 1.c -c
	gcc 2.c -c
	gcc 8.c -c
	gcc 9.c -c
	gcc 10.c -c
	gcc 11.c -c
	gcc 17.c -c
	gcc 18.c -c
	gcc init_pack.o bin_sem.o -lpthread -o init_pack
	gcc 1.o bin_sem.o -lpthread -o 1
	gcc 2.o bin_sem.o -lpthread -o 2
	gcc 8.o bin_sem.o -lpthread -o 8
	gcc 9.o bin_sem.o -lpthread -o 9
	gcc 10.o bin_sem.o -lpthread -o 10
	gcc 11.o bin_sem.o -lpthread -o 11
	gcc 17.o bin_sem.o -lpthread -o 17
	gcc 18.o bin_sem.o -lpthread -o 18
	gcc Makefifo.c -lpthread -o Makefifo
