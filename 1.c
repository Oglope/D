#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include "./bin_sem.h"

#define MAX_CHANNEL 3 //Количество бит, отвечающих за номер канала
#define MAX_ROUTE 10   //Количество бит, отвечающих за номер маршрута
//#define MAX_MASS 16  //Максимальное количество записей в таблицу маршрутизации
#define MIN_NUMBER 0   //Минимальный номер маршрута
#define M_SIZE 395	//Размер пакета (информационный)

#define TEST "./test"
#define PIPE12 "./1_2"

int pipe1_2, pipe1_8, pipe1_10, test;
int node1, node2, node8 , node10;

void output_3(char* buf) {

	int len;

	binary_semaphore_free(node2);
    if ( len = write(pipe1_2, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}

void output_4(char* buf) {

	int len;

	binary_semaphore_free(node8);
    if ( len = write(pipe1_8, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}

void output_6(char* buf) {

	int len;

	binary_semaphore_free(node10);
    if ( len = write(pipe1_10, buf, strlen(buf)-MAX_CHANNEL) <= 0)
    	perror("write");
}

int bin_to_dec (char *bin) {
	
	int len = strlen(bin)-1; 
	int dec=0;
	
	while (len>=0) {
		if (bin[strlen(bin)-len-1] == '1')
			dec = dec + pow (2,len);
		len--;
	}
	printf("dec = %d", dec);	
	return dec;
}

void build_route(int *mas_route, char* buf) {

	int i, route_num, channel;
	char route_char[MAX_ROUTE], channel_char[MAX_CHANNEL];
	
	for (i=0;i<MAX_ROUTE;i++) 
		route_char[i] = buf[i];
	
	route_num = bin_to_dec(route_char);
	
	for (i=0; i<MAX_CHANNEL; i++)
		channel_char[i] = buf[strlen(buf)-MAX_CHANNEL+i-1];
	
	channel = bin_to_dec(channel_char);
	
	printf("route = %d\n", route_num);
	printf("channel = %d\n", channel);
	
	mas_route[route_num] = channel;
	
	switch (channel) {
		case 0 :
			printf("\nDeliver sucessful");
			break;
		case 3 :
			output_3(buf);
			break;
		case 4 :
			output_4(buf);
			break;
		case 6 :
			output_6(buf);
			break;
		default :
			printf("\nError");
			break;
	}
}

void main(int argc,char* argv) {

//int Pipe12, test;
int len_read,i;
int mas_route[MAX_ROUTE];
//int node1, node2;
char buf[M_SIZE];

	binary_semaphore_initialize_0(node1);
	binary_semaphore_initialize_0(node2);
	binary_semaphore_initialize_0(node8);
	binary_semaphore_initialize_0(node10);
	
	if ( test = open(TEST, O_RDONLY)) {
    	perror("open");
    }

    if ( pipe1_2 = open(PIPE12, O_RDWR)) {
    	perror("open");
    }
    
    if ( pipe1_8 = open("./1_8", O_RDWR)) {
    	perror("open");
    }
    
    if ( pipe1_10 = open("./1_10", O_RDWR)) {
    	perror("open");
    }
    
    do {
    	memset(buf, '\0', M_SIZE);
    	binary_semaphore_take(node1);
        if (len_read = read(test, buf, M_SIZE-1)) {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        if (len_read = read(pipe1_2, buf, M_SIZE-1)) {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        if (len_read = read(pipe1_8, buf, M_SIZE-1)) {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        if (len_read = read(pipe1_10, buf, M_SIZE-1))  {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        //printf("Incomming message (%d): %s\n", len_read, buf);
        //build_route(mas_route, buf);
        
    } while ( 1 );
    
    close(pipe1_2);
    close(pipe1_8);
    close(pipe1_10);
    close(test);
	
}

