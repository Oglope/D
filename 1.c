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

#define TEST "./test"
#define PIPE12 "./1_2"

/*int input_packet (int first, int last, int mid,FILE* input) //Алгоритм поска маршрута в таблице маршрутизации
{
int k;
char y;
    for (k=0;k<M_R;k++)
    {
        y = fgetc(input);
        if (y=='1')
            first = mid+1;
        else
            last = mid;
        mid = (first+last)/2;
    }
    return mid;
}

int bin_to_dec (char* bin,int k,int n) //Функция перевода из двоичного в десятичное число
{
int dec=0,start;
    start = (n / (M_CH+M_R))*(M_CH+M_R);
    start = start + (n-start-k);
    for (; start<=n; ++start)
    {
        if (bin[start]=='1')
            dec=dec+pow(2,n-start);
    }
    return dec;
}*/

/*void build_route(int *mas_route, char* buf) {

	int i, n;
	
	for (i=0;*/
	

void main(int argc,char* argv) {

int pipe12, len_read, len_write, test;
int mas_route[MAX_ROUTE];
int node1, node2;
char buf[M_SIZE];

	binary_semaphore_initialize_0(node1);
	binary_semaphore_initialize_0(node2);
	if ( test = open(TEST, O_RDONLY)) {
    	perror("open");
    }

    if ( pipe12 = open(PIPE12, O_RDWR)) {
    	perror("open");
    }
    
    do {
    	memset(buf, '\0', M_SIZE);
    	binary_semaphore_take(node1);
        if ( (len_read = read(test, buf, M_SIZE-1)) <= 0 ) {
            perror("read");
        }
        printf("Incomming message (%d): %s\n", len_read, buf);
        binary_semaphore_initialize_0(node2);
        if ( len_write = write(pipe12, buf, len_read) <= 0)
    		perror("write");
        
    } while ( 1 );
    
    close(pipe12);
    close(test);
	
}

