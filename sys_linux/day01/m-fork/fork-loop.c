/*************************************************************************
	> File Name: fork-loop.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年02月19日 星期五 22时55分10秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int i = 0;
	pid_t pid;
	for(;i < 5; i++){
		pid = fork();
		if(pid == 0){
			break;
		}
	}
	
	if(pid == 0){
		printf("I am %dth %u child process.\n", i, getpid());
	}else{
		printf("I am father process.\n");
	}

	return 0;
}
