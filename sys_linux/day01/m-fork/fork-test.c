/*************************************************************************
	> File Name: fork-test.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月19日 星期五 17时18分29秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
	pid_t pid;//progress id
	printf("**************\n");
	pid = fork();
	if(pid == -1){
		perror("fork error:");
		exit(1);
	}else if(pid == 0){
		printf("I am child, pid = %u, ppid = %u\n", getpid(),getppid());
	}else{
		printf("I am father, pid = %u, ppid = %u\n", getpid(),getppid());
		sleep(3);
	}
	printf("mmmmmmmmmmmmmmmm\n");
	
	return 0;
}
