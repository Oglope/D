#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void main () {
	
	remove("./test");
	remove("./1_2");
	remove("./1_8");
	remove("./1_10");
	//remove("./2_3");
	remove("./2_9");
	remove("./2_11");
	remove("./8_9");
	remove("./8_17");
	remove("./9_18");
	remove("./10_11");
	remove("./10_17");
	remove("./11_18");
	remove("./17_18");
}
	
