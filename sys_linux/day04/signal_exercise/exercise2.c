/*************************************************************************
	> File Name: exercise2.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月06日 星期六 22时20分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
typedef (*sighandler_t)(int);

void catchsigint(int signo){
	printf("%d catched...\n", signo);
}

int main()
{
	sighandler_t handler = signal(SIGINT, catchsigint);
	if(handler == SIG_ERR){
		perror("signal err:");
		exit(1);
	}
	while(1);
	return 0;
}
