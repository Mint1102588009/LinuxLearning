/*************************************************************************
	> File Name: mmap_test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月01日 星期一 21时27分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	int ret;
	char* p = NULL;
	int fd = open("mytest.txt", O_RDWR | O_CREAT, 0644);
	if(fd < 0){
		perror("open error:");
		exit(1);
	}
	size_t len = (size_t)ftruncate(fd, 4);
	if(len == -1){
		perror("ftruncate error:");
		exit(1);
	}
	p = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		perror("mmap error:");
		exit(1);
	}
	strcpy(p, "Mint");
	ret = munmap(p, 4);
	if(ret == -1){
		perror("munmap error:");
		exit(1);
	}
	close(fd);

	return 0;
}
