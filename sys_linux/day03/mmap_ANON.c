/*************************************************************************
	> File Name: mmap_ANON.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月01日 星期一 23时34分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int * p = mmap(NULL, 4, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON, -1, 0);
	if(p == MAP_FAILED){
		perror("mmap error:");
		exit(1);
	}

	pid_t id = fork();
	if(id == 0){
		*p = 777;
		printf("child:*p = %d\n", *p);
	}else{
		wait(NULL);
		printf("parent:*p = %d\n", *p);
		int ret = munmap(p, 4);
		if(ret == -1){
			perror("munmap error:");
			exit(1);
		}
	}

	return 0;
}
