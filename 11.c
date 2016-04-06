#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include "./bin_sem.h"

#define MAX_CHANNEL 1 //Количество бит, отвечающих за номер канала
#define MAX_ROUTE 3   //Количество бит, отвечающих за номер маршрута
#define MAX_MASS 16  //Максимальное количество записей в таблицу маршрутизации
#define MIN_NUMBER 0   //Минимальный номер маршрута
#define M_SIZE 256

#define TEST "./test"

int pipe2_11, pipe10_11, pipe11_18, test;
int node2, node10, node11 , node18;

void output_1(char* buf) {

	int len;

	binary_semaphore_free(node2);
    if ( len = write(pipe2_11, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}

/*void output_3(char* buf) {

	int len;

	binary_semaphore_free(node12);
    if ( len = write(pipe11_12, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}*/

void output_4(char* buf) {

	int len;

	binary_semaphore_free(node18);
    if ( len = write(pipe11_18, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}

void output_5(char* buf) {

	int len;

	binary_semaphore_free(node10);
    if ( len = write(pipe10_11, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}

/*void output_6(char* buf) {

	int len;

	binary_semaphore_free(node20);
    if ( len = write(pipe11_20, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}*/

void build_route(int *mas_route, char* buf) {

	int i, route_num, channel;
	char route_char[MAX_ROUTE];
	
	for (i=0;i<MAX_ROUTE;i++) 
		route_char[i] = buf[i];
	
	route_num = atoi(route_char);
	channel = atoi(&buf[strlen(buf)-1]);
	
	printf("route = %d\n", route_num);
	printf("channel = %d\n", channel);
	
	mas_route[route_num] = channel;
	
	switch (channel) {
		case 0 :
			printf("\nDeliver sucessful");
			break;
		case 1 :
			output_1(buf);
			break;
		/*case 3 :
			output_3(buf);
			break;*/
		case 4 :
			output_4(buf);
			break;
		case 5 :
			output_5(buf);
			break;
		/*case 6 :
			output_6(buf):
			break;*/
		default :
			printf("Error");
			break;
	}
}

void main(int argc,char* argv) {

//int Pipe12, test;
int len_read,i;
int mas_route[MAX_ROUTE];
//int node1, node2;
char buf[M_SIZE];

	binary_semaphore_initialize_0(node2);
	binary_semaphore_initialize_0(node10);
	binary_semaphore_initialize_0(node11);
	binary_semaphore_initialize_0(node18);
	
	if ( test = open(TEST, O_RDONLY)) {
    	perror("open");
    }

    if ( pipe2_11 = open("./2_11", O_RDWR)) {
    	perror("open");
    }
    
    if ( pipe10_11 = open("./10_11", O_RDWR)) {
    	perror("open");
    }
    
    if ( pipe11_18 = open("./11_18", O_RDWR)) {
    	perror("open");
    }
    
    do {
    	memset(buf, '\0', M_SIZE);
    	binary_semaphore_take(node11);
        /*if ( (len_read = read(test, buf, M_SIZE-1)) <= 0 ) 
            perror("read");*/
        if ( (len_read = read(pipe2_11, buf, M_SIZE-1)) <= 0 ) 
            perror("read");
        if ( (len_read = read(pipe10_11, buf, M_SIZE-1)) <= 0 ) 
            perror("read");
        if ( (len_read = read(pipe11_18, buf, M_SIZE-1)) <= 0 ) 
            perror("read");
        printf("Incomming message (%d): %s\n", len_read, buf);
        build_route(mas_route, buf);
        
    } while ( 1 );
    
    close(pipe2_11);
    close(pipe10_11);
    close(pipe11_18);
    close(test);
	
}

