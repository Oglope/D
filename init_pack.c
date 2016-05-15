#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include "./bin_sem.h"



#define MAX_CHANNEL 3 //Количество бит, отвечающих за номер канала
#define MAX_ROUTE 10   //Количество бит, отвечающих за номер маршрута
#define MAX_MASS 1000  //Максимальное количество записей в таблицу маршрутизации
///#define MIN_NUMBER 0   //Минимальный номер маршрута
#define M_SIZE 395
#define MAX_NODE 2 //Количество узлов
#define TEST "./test"



void main() {

	int test,len,quest;
	int node1, node2, node8, node9, node11, node10, node17, node18;
	char buf[M_SIZE];
	
	key_t key1 = ftok("node1", 1);
	key_t key2 = ftok("node2", 1);
	key_t key8 = ftok("node8", 1);
	key_t key9 = ftok("node9", 1);
	key_t key10 = ftok("node10", 1);
	key_t key11 = ftok("node11", 1);
	key_t key17 = ftok("node17", 1);
	key_t key18 = ftok("node18", 1);
	
	node1 = binary_semaphore_allocation(key1, 0666 | IPC_CREAT);
	node2 = binary_semaphore_allocation(key2, 0666 | IPC_CREAT);
	node8 = binary_semaphore_allocation(key8, 0666 | IPC_CREAT);
	node9 = binary_semaphore_allocation(key9, 0666 | IPC_CREAT);
	node10 = binary_semaphore_allocation(key10, 0666 | IPC_CREAT);
	node11 = binary_semaphore_allocation(key11, 0666 | IPC_CREAT);
	node17 = binary_semaphore_allocation(key17, 0666 | IPC_CREAT);
	node18 = binary_semaphore_allocation(key18, 0666 | IPC_CREAT);
	
	binary_semaphore_initialize_0(node1);
	binary_semaphore_initialize_0(node2);
	binary_semaphore_initialize_0(node8);
	binary_semaphore_initialize_0(node9);
	binary_semaphore_initialize_0(node10);
	binary_semaphore_initialize_0(node11);
	binary_semaphore_initialize_0(node17);
	binary_semaphore_initialize_0(node18);
		
	
	if ( test = open("./test", O_RDWR)) {
    	perror("open");
    }
	
	do {
		printf("\nPacket");
		
		printf("\nChose node");
		scanf("%d",&quest);
		switch (quest) {
			case 1 :
				printf("\nPacket");
				scanf("%s",buf );
				if ( len = write(test, buf, strlen(buf)))
					binary_semaphore_free(node1);
    			else		
    				perror("write");
    			break;
    		case 2 : 
    			printf("\nPacket");
				scanf("%s",buf );
				if ( len = write(test, buf, strlen(buf)))
					binary_semaphore_free(node2);
    			else		
    				perror("write");
    			break;
    		default :
    			printf("\nError node");
    			break;
    	}	  	
    }
	while (1);
	
	close(test);

}
