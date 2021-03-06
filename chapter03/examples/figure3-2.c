#include "common.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(void){
	int fd;
	
	if((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("creat error\n");

	if(write(fd, buf1, 10) != 10)
		err_sys("buf1 write error\n");

	if(lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error\n");

	if(write(fd, buf2, 10) != 10)
	       err_sys("buf2 write error\n");

	exit(0);	
}
