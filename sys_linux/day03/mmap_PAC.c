/*************************************************************************
	> File Name: mmap_PAC.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月01日 星期一 22时48分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>

int var = 100;

int main()
{
	int fd = open("temp", O_RDWR | O_CREAT, 0664);
	if(fd == -1){
		perror("open error:");
		exit(1);
	}
	int* p;
	truncate("temp",4);
	p = mmap(NULL, 4, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd, 0);
	unlink("temp");
	close(fd);
	if(p == MAP_FAILED){
		perror("mmap error:");
		exit(1);
	}
//	*p = 777;	
	pid_t id = fork();
	if(id == 0){
		*p = 2000;
		var = 1000;
		printf("child:*p = %d, var = %d\n", *p, var);
	}else{
		wait(NULL);
		printf("parent:*p = %d, var = %d\n", *p, var);
		int ret = munmap(p, 4);
		if(ret == -1){
			perror("munmap error:");
			exit(1);
		}
	}

	return 0;
}
