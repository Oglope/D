#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void main () {
	
	mkfifo("./1_2", 0777);
	mkfifo("./1_8", 0777);
	mkfifo("./1_10", 0777);
	mkfifo("./2_3", 0777);
	mkfifo("./2_9", 0777);
	mkfifo("./2_11", 0777);
	/*mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);
	mkfifo(NAMEDPIPE_NAME, 0777);*/
}
	
