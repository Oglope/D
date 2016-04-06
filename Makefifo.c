#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void main () {
	
	mkfifo("./test", 0777);
	mkfifo("./1_2", 0777);
	mkfifo("./1_8", 0777);
	mkfifo("./1_10", 0777);
	//mkfifo("./2_3", 0777);
	mkfifo("./2_9", 0777);
	mkfifo("./2_11", 0777);
	mkfifo("./8_9", 0777);
	mkfifo("./8_17", 0777);
	mkfifo("./9_18", 0777);
	mkfifo("./10_11", 0777);
	mkfifo("./10_17", 0777);
	mkfifo("./11_18", 0777);
	mkfifo("./17_18", 0777);
}
	
