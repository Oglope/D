#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>

#define M_CH 3 //Количество бит, отвечающих за номер канала
#define M_R 4   //Количество бит, отвечающих за номер маршрута
#define M_M 16  //Максимальное количество записей в таблицу маршрутизации
#define M_N 0   //Минимальный номер маршрута
#define M_SIZE 256

#define PIPE12 "/home/oglope/D/1_2"

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

void main(int argc,char* argv) {

int pipe12, len;
int node2;
char buf[M_SIZE];

	binary_semaphore_initialize_0(node2);
    if ( pipe12 = open(PIPE12, O_RDWR)) {
    	perror("open");
    }

    
    do {
    	binary_semaphore_take(node2);
        if ( (len = read(pipe12, buf, M_SIZE-1)) <= 0 ) {
            perror("read");
        }
        printf("Incomming message (%d): %s\n", len, buf);
    } while ( 1 );
    
    close(pipe12);
    
 
}

