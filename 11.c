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
//#define MIN_NUMBER 0   //Минимальный номер маршрута
#define M_SIZE 395	//Размер пакета (информационный)

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

int bin_to_dec (char *bin) {
	
	int len = strlen(bin)-3; //-2 , т.к. 10 = длина, пишет = 11, нужно 9 (не забыть стереть)!!
	int dec = 0;
	
	printf("\nlen = %d", len);
	while (len>=0) {
		if (bin[strlen(bin)-len-3] == '1') //Костыль #2
			dec = dec + pow (2,len);
		len--;
	}
	printf("\ndec = %d", dec);	
	return dec;
}

void build_route(int *mas_route, char* buf) {

	int i, route_num, channel;
	char route_char[MAX_ROUTE], channel_char[MAX_CHANNEL];
	
	for (i=0; i<MAX_ROUTE; ++i) 
		route_char[i] = buf[i];
	
	printf("\nroute_char = %s",route_char);

	route_num = bin_to_dec(route_char);
	for (i=0; i<MAX_CHANNEL; i++)
		channel_char[i] = buf[strlen(buf)-MAX_CHANNEL+i];
		
	printf("\nchannel_char = %s",channel_char);
	
	channel = bin_to_dec(channel_char);
	
	printf("\nroute = %d", route_num);
	printf("\nchannel = %d", channel);
	
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
int mas_route[MAX_MASS];
//int node1, node2;
char buf[M_SIZE];

	key_t key2 = ftok("node2", 1);
	key_t key10 = ftok("node10", 1);
	key_t key11 = ftok("node11", 1);
	key_t key18 = ftok("node18", 1);
	
	node2 = binary_semaphore_allocation(key2, 0666);
	node10 = binary_semaphore_allocation(key10, 0666);
	node11 = binary_semaphore_allocation(key11, 0666);
	node18 = binary_semaphore_allocation(key18, 0666);

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
        if (len_read = read(pipe2_11, buf, M_SIZE-1)) {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        if (len_read = read(pipe10_11, buf, M_SIZE-1)) {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        if (len_read = read(pipe11_18, buf, M_SIZE-1)) {
        	printf("Incomming message (%d): %s\n", len_read, buf);
            build_route(mas_route, buf);
            continue;
        }
        //printf("Incomming message (%d): %s\n", len_read, buf);
        //build_route(mas_route, buf);
        
    } while ( 1 );
    
    close(pipe2_11);
    close(pipe10_11);
    close(pipe11_18);
    close(test);
	
}

