#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include "./bin_sem.h"

#define MAX_CHANNEL 3 //Количество бит, отвечающих за номер канала
#define MAX_ROUTE 4   //Количество бит, отвечающих за номер маршрута
#define MAX_MASS 16  //Максимальное количество записей в таблицу маршрутизации
#define MIN_NUMBER 0   //Минимальный номер маршрута
#define M_SIZE 256
#define MAX_NODE 2 //Количество узлов
#define TEST "./test"



void main() {

	int test,i,len,sem_node[MAX_NODE];
	int node1,node2;
	char buf[M_SIZE];
	
	key_t key1 = ftok("node1", 1);
	key_t key2 = ftok("node2", 1);
	node1 = binary_semaphore_allocation(key1, 0666 | IPC_CREAT);
	node2 = binary_semaphore_allocation(key2, 0666 | IPC_CREAT);
	binary_semaphore_initialize_0(node1);
	binary_semaphore_initialize_0(node2);
	
	for (i=0; i<MAX_NODE; i++)
		
	
	if ( test = open(TEST, O_RDWR)) {
    	perror("open");
    }
	
	do {
		scanf("%s",buf);
		if ( len = write(test, buf, strlen(buf)))
			binary_semaphore_free(node1);
    	else		
    		perror("write");
    	
    }
	while (1);
	
	close(test);

}
