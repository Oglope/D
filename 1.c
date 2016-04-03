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
}

void output_1(FILE* out)    //Выход 1-го канала
{
    printf("Channel 1\n");
    return out;
}

void output_2(FILE* out)    //Выход 2-го канала
{
    printf("Channel 2\n");
    return out;
}

void output_3(FILE* out)    //Выход 3-го канала
{
    printf("Channel 3\n");
    return out;
}

void output_4(FILE* out)    //Выход 4-го канала
{
    printf("Channel 4\n");
    return out;
}

void output_5(FILE* out)    //Выход 5-го канала
{
    printf("Channel 5\n");
    return out;
}

void output_6(FILE* out)    //Выход 6-го канала
{
    printf("Channel 6\n");
    return out;
}*/

void main(int argc,char* argv) {

int rt_d, ch_d, i=0, j=0, flag=0, mas_rc[M_M], pipe12, len, test;
char buff[(M_R+M_CH)*(M_M+1)];
char buf[M_SIZE];

	if ( test = open(TEST, O_RDONLY)) {
    	perror("open");
    }

    if ( pipe12 = open(PIPE12, O_RDWR)) {
    	perror("open");
    }
    
    if ( len = write(pipe12, "Hello_world", M_SIZE-1))
    	perror("write");
    
    do {
        if ( (len = read(test, buf, strlen(buf))) <= 0 ) {
            perror("read");
        }
        else
        	printf("Incomming message (%d): %s\n", len, buf);
        
    } while ( len );
    

      /*  while(fgets(buf,(M_R+M_CH)*(M_M+1),route)) //Составляем таблицу маршрутизации
        {
            for(; i<strlen(buf); ++i)
            {
                if (j==M_R-1 && flag==0)
                {
                    rt_d = bin_to_dec(buf,M_R-1,i);
                    flag=1;
                    j=-1;
                }

                if (j==M_CH-1 && flag==1)
                {
                    ch_d = bin_to_dec(buf,M_CH-1,i);
                    flag=0;
                    j=-1;
                    mas_rc[rt_d] = ch_d;
                }
                j++;
            }
        }
    }
    fclose(route); 

    while(1)
    {
      scanf("%s",pack_name);
        if (pack = fopen(pack_name,"r")) //Если блок принят, то ищем нужный канал по таблице
        {
            switch(mas_rc[input_packet(M_N,M_M-1,(M_N+M_M-1)/2,pack)]) //Поиск канала, и последующий перевод блока в нужный канал
            {
                case 1 :
                    output_1(pack);
                    break;
                case 2 :
                    output_2(pack);
                    break;
                case 3 :
                    output_3(pack);
                    break;
                case 4 :
                    output_4(pack);
                    break;
                case 5 :
                    output_5(pack);
                    break;
                case 6 :
                    output_6(pack);
                    break;
                default :
                    printf("Error\n");
            }
            fclose(pack);
        }
        else
            printf("Error package\n");
        }*/
       close(pipe12);
	
}

