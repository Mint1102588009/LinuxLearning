/*************************************************************************
	> File Name: exercise3.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月06日 星期六 23时13分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void catchSig(int signo){
	printf("hello %d!\n", signo);
	sleep(20);
}

int main(){
	sigset_t set;
	struct sigaction act;
	sigfillset(&set);
	act.sa_mask = set;
	act.sa_handler = catchSig;
	act.sa_flags = 0;
	int ret = sigaction(SIGINT, &act, NULL);
	if(ret == -1){
		perror("sigaction err:");
		exit(1);
	}
	while(1);

	return 0;
}
