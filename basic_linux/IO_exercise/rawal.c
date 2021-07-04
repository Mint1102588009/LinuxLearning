/*************************************************************************
	> File Name: rawal.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月01日 星期一 11时42分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1 = open("./elf.h", O_RDONLY);
	int fd2 = open("./temp", O_WRONLY | O_CREAT | O_APPEND, 0664);
	char buf[1024];
	int ret = read(fd1, buf, sizeof(buf));
	while(ret > 0){
		write(fd2, buf, ret);	
		ret = read(fd1, buf, sizeof(buf));
	}
	close(fd1);
	close(fd2);
	return 0;
}
