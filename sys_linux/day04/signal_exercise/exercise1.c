/*************************************************************************
	> File Name: exercise1.c
	> Author: Mint_7
	> Mail: 1102588009@qq.com 
	> Created Time: 2021年03月06日 星期六 21时26分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	sigset_t set, oldset, pset;
	int ret = sigfillset(&set);//创建信号集
	if(ret == -1){
		perror("sigemptyset err:");
	}
	ret = sigprocmask(SIG_BLOCK, &set, &oldset);//设置阻塞信号集
	if(ret == -1){
		perror("sigprocmask err:");
	}
	while(ret == 0){
		ret = sigpending(&pset);
		for(int i = 1; i < 32; i++){
			if(sigismember(&pset, i) == 1){
				putchar('1');
			}else{
				putchar('0');
			}
		}
		printf("\n");
		sleep(3);
	}

	return 0;
}
