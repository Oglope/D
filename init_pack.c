#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

#define MAX_CHANNEL 3 //Количество бит, отвечающих за номер канала
#define MAX_ROUTE 4   //Количество бит, отвечающих за номер маршрута
#define MAX_MASS 16  //Максимальное количество записей в таблицу маршрутизации
#define MIN_NUMBER 0   //Минимальный номер маршрута
#define M_SIZE 256
//#define MAX_NODE 2 //Количество узлов
#define TEST "./test"

sem_t node; //Массив семафоров по нодам

void main() {

	int test,i,len;
	char buf[M_SIZE];
	sem_init(&node, 1, 0);
	
	//for (i=0; i<MAX_NODE; i++)
	//sem_init(&node1, 1,0);
	
	if ( test = open(TEST, O_RDWR)) {
    	perror("open");
    }
	
	do {
		scanf("%s",buf);
		if ( len = write(test, buf, strlen(buf)))
			sem_post(&node);
    	else		
    		perror("write");
    	
    }
	while (1);
	
	close(test);

}
